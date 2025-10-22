cmake_minimum_required(VERSION 3.16)
project(aim_training)



set(CMAKE_CXX_STANDARD 23)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_subdirectory(Core)
add_subdirectory(App)
# Create your game executable target as usual
# add_executable(hello WIN32 hello.c)

