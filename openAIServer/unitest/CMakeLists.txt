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
