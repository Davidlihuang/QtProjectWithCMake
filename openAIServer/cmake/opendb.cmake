cmake_minimum_required(VERSION 3.20.0)
# 添加第三方依赖包
include(FetchContent)
include(macrofunc)

if(${CMAKE_VERSION} VERSION_LESS 3.14)
    include(add_FetchContent_MakeAvailable.cmake)
endif()

# 定义 变量
set(DEP_NAME opendb)
set(DEP_GIT_TAG master)
set(DEP_GIT_URL https://gitee.com/who__knows/OpenDB.git)
set(LIBRARY_INSTALL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/thirdlib/${DEP_NAME}")

FetchContent_Declare(
  ${DEP_NAME}
  GIT_REPOSITORY    ${DEP_GIT_URL}
  GIT_TAG           ${DEP_GIT_TAG}
  SOURCE_DIR ${LIBRARY_INSTALL_DIR}
)

MFetchContent_MakeAvailable("${DEP_NAME}")
message(STATUS "fetch ${DEP_NAME} finish...")