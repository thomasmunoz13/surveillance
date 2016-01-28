cmake_minimum_required(VERSION 3.3)
project(surveillance)
find_package(OpenCV REQUIRED)

set(DEBUG "-DDEBUG")
set(DEBUG_LEVEL "0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 ${DEBUG}=${DEBUG_LEVEL}")

set(SOURCE_FILES
        src/motion.cpp
        src/Webcam.cpp
        src/Webcam.h
        src/WebcamNotFoundException.cpp
        src/WebcamNotFoundException.h
        src/VideoDisplay.cpp
        src/VideoDisplay.h
        src/App.cpp
        src/App.h
        src/MotionTrack.cpp
        src/MotionTrack.h)

add_executable(surveillance ${SOURCE_FILES})

target_link_libraries(surveillance ${OpenCV_LIBS})