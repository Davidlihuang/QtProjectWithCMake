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
#设置编译选项
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_STANDARD 17) #c++标准
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#`-Wall`：开启所有警告信息。这意味着编译器会输出所有可能的问题，包括潜在的错误和不规范的代码
#`-g`：添加调试信息。这意味着编译器会在生成的可执行文件中包含调试信息，以便在运行时进行调试。
#`-rdynamic`：允许动态链接。这意味着编译器会在生成的可执行文件中包含符号表信息，以便在运行时动态链接库时使用。
add_definitions("-Wall -g -rdynamic")


#操作系统识别
IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
  MESSAGE(STATUS "current platform: Linux ")
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
  MESSAGE(STATUS "current platform: Windows")
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
  MESSAGE(STATUS "current platform: FreeBSD")
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Darwin")
  MESSAGE(STATUS "current platform: MacOS")
  set(OPENSSL_ROOT_DIR "/usr/local/opt/openssl" )
  set(OPENSSL_LIBRARIES "/usr/local/opt/openssl/lib" )
  set(OPENSSL_INCLUDE_DIR "/usr/local/opt/openssl/include" )
ELSE ()
  MESSAGE(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")


#设置文件生成路径BUILD_SERVER
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


# 配置第三方库
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake;${CMAKE_MODULE_PATH}")
include(spdlog2)
include(json)


#project build
add_subdirectory(source)
add_subdirectory(unitest)
