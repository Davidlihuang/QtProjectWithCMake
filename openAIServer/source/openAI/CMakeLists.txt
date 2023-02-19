cmake_minimum_required(VERSION 3.20.0)
set(projectName "openAI")
project(${projectName})

#创建静态库
add_library(${PROJECT_NAME} STATIC openAI.cpp )

#静态库起别名
add_library(lib::openAI ALIAS ${PROJECT_NAME} ) 

#包含头文件
target_include_directories(${PROJECT_NAME} PUBLIC  .)
target_include_directories(${PROJECT_NAME} PUBLIC  ./Completion)
#compile sub-moudle of openai
add_subdirectory(Completion)
add_subdirectory(Deployment)
add_subdirectory(Edit)
add_subdirectory(Embedding)
add_subdirectory(Engine)
add_subdirectory(ErrorObject)
add_subdirectory(File)
add_subdirectory(FineTune)
add_subdirectory(Image)
add_subdirectory(Model)
add_subdirectory(Moderation)

#link sub moudle 
set(LIBS lib::Complection lib::Image lib::Engine lib::ErrorObject lib::Deployment lib::File lib::FineTune lib::Model lib::Moderation)


target_link_libraries(${PROJECT_NAME} ${LIBS}) 