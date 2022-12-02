cmake_minimum_required(VERSION 3.20.0 )

set(PROJECT_NAME "Laplace")

project(${PROJECT_NAME})

find_package(OpenCV REQUIRED core highgui imgproc)

add_executable(${PROJECT_NAME} Laplace.cpp)

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})