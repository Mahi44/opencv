cmake_minimum_required(VERSION 2.8.12)
set(PROJECT_NAME "SobelTest")

project(${PROJECT_NAME})

find_package(OpenCV REQUIRED core imgproc highgui) 

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} Sobel.cpp)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

