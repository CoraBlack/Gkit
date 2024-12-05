cmake_minimum_required(VERSION 3.10)

project(Cppgame)

# cmake and cxx basic setting
set(LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../bin)
set(CXX_STANDARD_REQUIRED ON)
set(CXX_STANDARD 17)

# Search source file
set(SRC 
    ./Asset/Asset.cpp 
    ./Graphics/Window.cpp
)

# Set include and link
include_directories("G:\\CppLib\\SDL2-2.30.6\\include")
include_directories("G:\\CppLib\\SDL2_image-2.8.2\\include")
file(GLOB_RECURSE LIB_DIR ${CMAKE_SOURCE_DIR}/../lib/*.lib)


add_library(cppgame_lib STATIC ${SRC})
add_library(cppgame_dll SHARED ${SRC})

target_link_directories(cppgame_lib PRIVATE ${LIB_DIR})
target_link_directories(cppgame_dll PRIVATE ${LIB_DIR})