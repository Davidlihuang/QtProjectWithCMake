cmake_minimum_required(VERSION 3.20.0)
set(projectName "Deployment")
project(${projectName})

#创建静态库
add_library(${PROJECT_NAME} STATIC deployment.cpp )

#静态库起别名
add_library(lib::Deployment ALIAS ${PROJECT_NAME} ) 

#包含头文件
target_include_directories(${PROJECT_NAME} PUBLIC  .)

# #link sub moudle
# set(LIBS lib::complection lib::Image lib::Engine lib::ErrorObject lib::Deployment lib::File lib::FineTune lib::Model lib::Moderation)
# target_link_libraries(${PROJECT_NAME} ${LIBS}) 