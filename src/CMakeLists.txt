cmake_minimum_required(VERSION 3.10)

project(Gkit)

# cmake and cxx basic setting
set(LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../bin)
set(CXX_STANDARD_REQUIRED ON)
set(CXX_STANDARD 17)

# Search source file
set(SRC 
    # Asset
    ./Asset/Asset.cpp 
    ./Asset/Image.cpp 
    ./Asset/Sprite.cpp 

    # Graphics
    ./Graphics/Window.cpp
    ./Graphics/Camera.cpp
    
    # GameObject
    ./GameObject/Actor.cpp

    #Scenario
    ./Scenario/Scenario.cpp

    # Gkit
    ./Gkit.cpp
)

# include_directories("C:/msys64/mingw64/lib/cmake")

# Static link SDL2
set(SDL_STATIC ON)
set(BUILD_SHARED_LIBS OFF) 
set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")

# find SDL2 package
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

# Include path
include_directories(Gkit ${CMAKE_SOURCE_DIR})
include_directories(Gkit ${CMAKE_SOURCE_DIR}/Asset)
include_directories(Gkit ${CMAKE_SOURCE_DIR}/Sprite)
include_directories(Gkit ${CMAKE_SOURCE_DIR}/GameObject)
include_directories(Gkit ${SDL2_INDLUDE_DIRS})

add_library(Gkit SHARED ${SRC})

target_link_libraries(Gkit PRIVATE SDL2 SDL2main SDL2_test)
target_link_libraries(Gkit PRIVATE SDL2_image)
target_link_libraries(Gkit PRIVATE SDL2_ttf)