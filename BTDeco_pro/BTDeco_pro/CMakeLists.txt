#指定cmake的最小版本号
CMAKE_MINIMUM_REQUIRED(VERSION 3.20.0)
include(FetchContent)
#指定项目名称
PROJECT(BTDECO LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE "Debug") #Release 如果是发行版本就更换Debug为Release
if(CMAKE_BUILD_TYPE STREQUAL Debug)
    add_definitions(-D_DEBUG) #添加D_DEBUG编译参数
endif()

# 设置编译参数
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")


# 设置编译工具链，备用
#set(COMPILER_PREFIX "arm-linux-")
#set(CMAKE_C_COMPILER ${COMPILER_PREFIX}gcc)
#set(CMAKE_CXX_COMPILER ${COMPILER_PREFIX}g++)


# 环境设置
SET(CMAKE_INCLUDE_CURRENT_DIR ON)



#QT设置
#指定Qt路径和启用当前目录(按需设置),兼容window和linux
IF(WIN32)
    message("In windows")
    SET(CMAKE_PREFIX_PATH " D:\\software\\qt\\5.12.11\\mingw73_64\\lib\\cmake")
    set(Qt5_DIR ${CMAKE_PREFIX_PATH}\\Qt5)
    message(${Qt5_DIR})
ELSE()
    SET(CMAKE_PREFIX_PATH " /opt/Qt5.13.0/5.13.0/gcc_64/lib/cmake")
    set(Qt5_DIR ${CMAKE_PREFIX_PATH}/Qt5)
    message(${Qt5_DIR})
    message("In linux like")
ENDIF()
find_package(Qt5 COMPONENTS Core Gui Widgets Sql  Network Concurrent Multimedia REQUIRED)






#将各种文件归类到指定变量
FILE(GLOB_RECURSE HEADER_FILES ${CMAKE_SOURCE_DIR}/include/*.h)
FILE(GLOB_RECURSE SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)
FILE(GLOB_RECURSE FORMS ${CMAKE_SOURCE_DIR}/form/ui/*.ui)
FILE(GLOB_RECURSE RESOURCE_FILES ${CMAKE_SOURCE_DIR}/form/qrc/*.qrc)
FILE(GLOB TS_FILES ${CMAKE_SOURCE_DIR}/form/ts/*.ts)
FILE(GLOB MOC_FILES "moc_*.cpp")

#将ui文件编译成ui_*.h文件
IF(FORMS)
    QT5_WRAP_UI(FORMS_UIC ${FORMS})
    message("forms gen" ${FORMS_UIC})
ENDIF()

#将包含Q_OBJECT的头文件编译成moc_*.cpp文件
QT5_WRAP_CPP(MOC_FILES ${HEADER_FILES})

#启用qrc资源文件
QT5_ADD_RESOURCES(RES_FILES ${RESOURCE_FILES})

#启用当前头文件目录
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

#将ui文件和生成文件整理在一个文件夹中
SOURCE_GROUP("Form Files" FILES ${FORMS})
#将qrc资源文件整理在一个文件夹中
SOURCE_GROUP("Resource Files" FILES ${RESOURCE_FILES})
#查找当前目录下所有的.h和.cpp文件
SOURCE_GROUP("Header Files" FILES ${HEADER_FILES})
SOURCE_GROUP("Source Files" FILES ${SRC_FILES})
#翻译文件
SOURCE_GROUP("Translation Files" FILES ${TS_FILES})

#将MOC,UI,QRC的中间生成文件编译进EXE中
SOURCE_GROUP("Generated Files" FILES ${MOC_FILES} ${FORMS_UIC} ${RES_FILES} ${TS_FILES})

#引入库目录路径
LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/x64)

#将所有文件编译成EXE,并设置以WIN32的方式运行
IF(WIN32)
    ADD_EXECUTABLE(${PROJECT_NAME} WIN32 ${HEADER_FILES} ${SRC_FILES} ${MOC_FILES} ${FORMS_UIC} ${RESOURCE_FILES} ${RES_FILES})
ELSE()
    ADD_EXECUTABLE(${PROJECT_NAME}  ${HEADER_FILES} ${SRC_FILES} ${MOC_FILES} ${FORMS_UIC} ${RESOURCE_FILES} ${RES_FILES})
ENDIF()

#设置EXE文件的输出目录
SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/x64)

#包含自动文件生成文件的路径
INCLUDE_DIRECTORIES(${AUTOGEN_BUILD_DIR})
message("auto gen file:${AUTOGEN_BUILD_DIR}")

#链接以上lib库
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${PROJECT_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC "./include")




#第三方工具库
#spdlog
FetchContent_Declare(
    spdlog 
    GIT_REPOSITORY  git@github.com:gabime/spdlog.git
    GIT_TAG v1.11.0
    SOURCE_DIR
    ${CMAKE_SOURCE_DIR}/lib/spdlog)

FetchContent_MakeAvailable(spdlog)   


#启用Qt的库模块
TARGET_LINK_LIBRARIES( ${PROJECT_NAME} Qt5::Multimedia Qt5::Widgets Qt5::Core Qt5::Gui Qt5::Sql Qt5::Network Qt5::Concurrent spdlog::spdlog)
#QT5_USE_MODULES(${PROJECT_NAME} Widgets Core Gui Sql Multimedia Network Concurrent)

