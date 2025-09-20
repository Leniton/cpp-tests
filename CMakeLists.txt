cmake_minimum_required(VERSION 3.10)

project(MySDL2App VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find SDL2
find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)

# Include SDL2 headers
include_directories(${SDL2_INCLUDE_DIRS})

# Add your source files
add_executable(MySDL2App main.cpp)

# Link SDL2 libraries
target_link_libraries(MySDL2App ${SDL2_LIBRARIES})
