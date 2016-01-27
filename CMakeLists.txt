cmake_minimum_required(VERSION 3.3)
project(surveillance)
find_package( OpenCV REQUIRED )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES motion.cpp Webcam.cpp Webcam.h WebcamNotFoundException.cpp WebcamNotFoundException.h VideoDisplay.cpp VideoDisplay.h App.cpp App.h)
add_executable(surveillance ${SOURCE_FILES})

target_link_libraries(surveillance ${OpenCV_LIBS})