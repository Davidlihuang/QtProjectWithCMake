
cmake_minimum_required(VERSION 3.20.0)
project(qrc)

#c++标准
set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

#处理头文件
# set(RESOURCE_DIR form.qrc)
file(GLOB file_h "./*.h")
file(GLOB RESOURCE_DIR "./*.qrc")
qt5_add_resources(RCC ${RESOURCE_DIR}) #Moctool自动处理为qrc_xxx.cpp，因此需要将${Moctool}作源文件处理

#编译库文件
add_library(${PROJECT_NAME} STATIC
    ${RCC}
)
add_library(lib::formqrc ALIAS ${PROJECT_NAME})

#包含头文件
target_include_directories(${PROJECT_NAME} PUBLIC  ./) 

#当前静态库链接qt5，不然会有找不到头文件的错误
set(Qt5lib Qt5::Core Qt5::Gui Qt5::Widgets)
target_link_libraries(${PROJECT_NAME} ${Qt5lib}) 