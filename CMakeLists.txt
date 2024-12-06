cmake_minimum_required(VERSION 3.10)

project(Gkit)

# cmake and cxx basic setting
set(LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../bin)
set(CXX_STANDARD_REQUIRED ON)
set(CXX_STANDARD 17)

# Search source file
set(SRC 
    ./Asset/Asset.cpp 
    ./Asset/Sprite.h 
    ./Graphics/Window.cpp 
    ./GameObject/Actor.h
)

include_directories("C:/msys64/mingw64/lib/cmake")

# Include path
include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/Asset)
include_directories(${CMAKE_SOURCE_DIR}/Sprite)
include_directories(${CMAKE_SOURCE_DIR}/GameObject)
include_directories(${SDL2_INDLUDE_DIRS})

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

add_library(Gkit SHARED ${SRC})

target_link_libraries(Gkit PRIVATE STATIC SDL2 SDL2main SDL2test)
target_link_directories(Gkit PRIVATE STATIC SDL2_image)
target_link_directories(Gkit PRIVATE STATIC SDL2_ttf)