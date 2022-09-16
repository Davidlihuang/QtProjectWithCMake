project(colorswatch)

qt5_wrap_cpp(Moccs colorswatch.h) 
add_library(${PROJECT_NAME} STATIC
            colorswatch.cpp
            ${Moccs} 
)
add_library(lib::colorswatch ALIAS ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PUBLIC .)

#当前静态库链接qt5，不然会有找不到头文件的错误
set(Qt5lib Qt5::Core Qt5::Gui Qt5::Widgets)
target_link_libraries(${PROJECT_NAME} ${Qt5lib}) 