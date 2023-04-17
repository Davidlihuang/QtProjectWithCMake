# 添加第三方依赖包
include(FetchContent)
include(macrofunc)

# FetchContent_MakeAvailable was not added until CMake 3.14
if(${CMAKE_VERSION} VERSION_LESS 3.14)
    include(add_FetchContent_MakeAvailable.cmake)
endif()


set(SPDLOG_GIT_TAG  v1.4.1)                                # 指定版本
#set(SPDLOG_GIT_URL  https://github.com/gabime/spdlog.git)  # 指定git仓库地址
set(SPDLOG_GIT_URL  https://gitee.com/who__knows/spdlog.git)  # 指定git仓库地址git@gitee.com:who__knows/spdlog.git
set(LIBRARY_INSTALL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/thirdlib/spdlog") #指定库下载地址
message(STATUS "deps downloads to third path: ${LIBRARY_INSTALL_DIR}")

FetchContent_Declare(
  spdlog
  GIT_REPOSITORY    ${SPDLOG_GIT_URL}
  GIT_TAG           ${SPDLOG_GIT_TAG}
  SOURCE_DIR ${LIBRARY_INSTALL_DIR}
)
message(STATUS "name: spdlog. version: ${SPDLOG_GIT_TAG}. url: ${SPDLOG_GIT_URL}")
message(STATUS "Fetching spdlog ...")

MFetchContent_MakeAvailable(spdlog)
message(STATUS "fetch spdlog finish...")