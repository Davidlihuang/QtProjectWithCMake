cmake_minimum_required(VERSION 3.20.0)
set(projectName "painterProj")
project(${projectName})

include_directories(./mainwindow)
include_directories(./painter)
add_subdirectory(mainwindow)
add_subdirectory(painter)
add_subdirectory(gui)

# set(RESOURCE_DIR qrc/mainwindow.qrc)
# qt5_add_resources(RCC qrc/mainwindow.qrc)

set(LIBS lib::formqrc lib::mainwin lib::uiInflib2 lib::painter)
add_executable(${PROJECT_NAME} main.cc)

#和Qt库链接
target_link_libraries(${PROJECT_NAME} ${LIBS})
