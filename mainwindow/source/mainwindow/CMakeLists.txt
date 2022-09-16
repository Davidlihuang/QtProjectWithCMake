project(mainwindow)

# moc 头文件
qt5_wrap_cpp(Mocmw mainwindow.h )

#创建静态库
add_library(${PROJECT_NAME} STATIC mainwindow.cpp ${Mocmw}
)
add_library(lib::mainwin ALIAS ${PROJECT_NAME} ) #静态库起别名

#包含头文件
target_include_directories(${PROJECT_NAME} PUBLIC  .)

#当前静态库链接qt5，不然会有找不到头文件的错误
set(Qt5lib Qt5::Core Qt5::Gui Qt5::Widgets)
target_link_libraries(${PROJECT_NAME} ${Qt5lib}) 