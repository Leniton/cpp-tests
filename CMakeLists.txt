cmake_minimum_required(VERSION 3.10)

project(MySDL2App VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)

# Add executable
add_executable(MySDL2App main.cpp)

# Link SDL3 and SDL3_image
target_link_libraries(MySDL2App SDL3::SDL3 SDL3_image::SDL3_image)