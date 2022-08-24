cmake_minimum_required(VERSION 3.16)

project(notebook)

set(CMAKE_CXX_FLAGS "-g")

file(GLOB SRC CONFIGURE_DEPENDS "src/*.cpp")

add_executable(${PROJECT_NAME} ${SRC})
