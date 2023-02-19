cmake_minimum_required(VERSION 3.20.0)
set(projectName, "chatGPT")
project(projectName)

include (TestBigEndian)
test_big_endian(IS_BIG_ENDIAN)
if(IS_BIG_ENDIAN)
 message("BIG_ENDIAN")
else()
 message("LITTLE_ENDIAN")
endif()


#c++标准
set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

#设置文件生成路径
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)  #设置可执行文件生成路径
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/libarary/static)    #设置静态库路径
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/libarary/dynamic)    #设置动态库路径


#查找需要的包
set(CMAKE_PREFIX_PATH "/opt/Qt5.12.12/5.12.12/gcc_64/")
set(Qt_DIR ${CMAKE_PREFIX_PATH}/lib/cmake/Qt5)
set(QtWidgets_DIR ${CMAKE_PREFIX_PATH}/lib/cmake/Qt5Widgets)
set(QtCore_DIR ${CMAKE_PREFIX_PATH}/lib/cmake/Qt5Core)
set(QtGui_DIR ${CMAKE_PREFIX_PATH}/lib/cmake/Qt5Gui)

#qt开启MOC、RCC、UIC， 在预处理前进行moc, rcc, uic操作
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE _INCLUDE_CURRENT_DIR ON)
find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)




#project build
option(BUILD_TEST "Builds the unitest subproject" ON)
if(BUILD_SERVER)
    add_subdirectory(unitest)
else()
    add_subdirectory(source)
endif()
