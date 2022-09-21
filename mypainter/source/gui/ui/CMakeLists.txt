cmake_minimum_required(VERSION 3.20.0)
project(formui)

#c++标准
set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
file(GLOB file_ui "./*.ui")
QT5_WRAP_UI(ui_FILES ${file_ui} )
add_library(${PROJECT_NAME} INTERFACE)   #定义的一个接口库
add_library(sub::uiInterfacelib2 ALIAS ${PROJECT_NAME}) #接口库给别名为sub::lib2

target_include_directories(${PROJECT_NAME} #接口库包含头文件接口
    INTERFACE
        ${ui_FILES}
)