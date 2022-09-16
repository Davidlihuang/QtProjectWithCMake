cmake_minimum_required(VERSION 3.20.0)
set(projectName "BTDPcb")
project(${projectName})

add_subdirectory(mainwindow)
add_subdirectory(toolbar)
add_subdirectory(colorswatch)
add_subdirectory(qrc)
add_subdirectory(ui)

# set(RESOURCE_DIR qrc/mainwindow.qrc)
# qt5_add_resources(RCC qrc/mainwindow.qrc)

set(LIBS lib::qrc lib::mainwin lib::toolbar lib::colorswatch)
add_executable(${PROJECT_NAME} main.cpp ${RESOURCE_DIR} )

#和Qt库链接
target_link_libraries(${PROJECT_NAME} ${LIBS})