
project(toolbar)

#处理头文件
qt5_wrap_cpp(Moctool toolbar.h ) #Moctool自动处理为moc_toolbar.cpp，因此需要将${Moctool}作源文件处理

#编译库文件
add_library(${PROJECT_NAME} STATIC
    toolbar.cpp
    ${Moctool}
)
add_library(lib::toolbar ALIAS ${PROJECT_NAME})

#包含头文件
target_include_directories(${PROJECT_NAME} PUBLIC  ./) 

#当前静态库链接qt5，不然会有找不到头文件的错误
set(Qt5lib Qt5::Core Qt5::Gui Qt5::Widgets)
target_link_libraries(${PROJECT_NAME} ${Qt5lib}) 