cmake_minimum_required(VERSION 3.20.0)
set(projectName "robotServer")
project(${projectName})

#创建静态库
add_library(${PROJECT_NAME} STATIC robotserver.cpp )

#静态库起别名
add_library(lib::robotServer ALIAS ${PROJECT_NAME} ) 

#包含头文件
target_include_directories(${PROJECT_NAME} PUBLIC  .)

# #link sub moudle
set(LIBS lib::openAI)
set(PISTACHE_LIBRARY  "/usr/local/lib/libpistache.so")
set(EXTRA_LIBRARY "-pthread  -lssl -lcurl")
set(LIBRARIES_SEARCH_PATHS ${PISTACHE_LIBRARY} ${EXTRA_LIBRARY} ${LIBS})
target_link_libraries(${PROJECT_NAME} ${LIBRARIES_SEARCH_PATHS}) 