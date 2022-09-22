cmake_minimum_required(VERSION 3.20.0)
set(projectName "gui")
project(${projectName})

add_subdirectory(qrc)
add_subdirectory(ui)

# set(RESOURCE_DIR qrc/mainwindow.qrc)
# qt5_add_resources(RCC qrc/mainwindow.qrc)

#和Qt库链接
#target_link_libraries(${PROJECT_NAME} ${LIBS})
