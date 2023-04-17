cmake_minimum_required(VERSION 3.20.0)
set(projectName "chatGPTServer")
project(${projectName})





# set(RESOURCE_DIR qrc/mainwindow.qrc)
# qt5_add_resources(RCC qrc/mainwindow.qrc)


set(LIBS  lib::robotServer)

# compile sub moudle
add_subdirectory(openAI)
add_subdirectory(robotServer)
add_subdirectory(qrc)
add_subdirectory(ui)

add_executable(${PROJECT_NAME} main.cpp)
include_directories(./openAI ./robotServer  ./qrc  ./ui)
include_directories(${HEADER_SEARCH_PATHS})

#和Qt库链接
set(Qt5lib Qt5::Core Qt5::Gui Qt5::Widgets)
target_link_libraries(${PROJECT_NAME} ${LIBS}  spdlog::spdlog nlohmann_json::nlohmann_json )
