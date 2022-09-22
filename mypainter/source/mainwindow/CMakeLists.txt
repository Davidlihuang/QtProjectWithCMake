project(mainwindow)

file(GLOB file_h "./*.h")
file(GLOB file_cc "./*.cc")

# moc 头文件
qt5_wrap_cpp(Mocmw ${file_h} )
set(sourcefile ${file_cc} ${Mocmw} )
#创建静态库
add_library(${PROJECT_NAME} STATIC ${sourcefile})
add_library(lib::mainwin ALIAS ${PROJECT_NAME} ) #静态库起别名

#包含头文件
target_include_directories(${PROJECT_NAME} PUBLIC  ${file_h})

#当前静态库链接qt5，不然会有找不到头文件的错误
set(Qt5lib Qt5::Core Qt5::Gui Qt5::Widgets)
target_link_libraries(${PROJECT_NAME} ${Qt5lib}) 