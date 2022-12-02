cmake_minimum_required(VERSION 3.20.0)

set(PROJECT_NAME "InvertRGB")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x")

project(${PROJECT_NAME})

find_package(OpenCV REQUIRED core highgui imgproc)

add_executable(${PROJECT_NAME} InvertRGB.cpp)

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

