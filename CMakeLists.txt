cmake_minimum_required(VERSION 3.3)
project(surveillance)
find_package(OpenCV REQUIRED)

set(DEBUG "-DDEBUG")
set(DEBUG_LEVEL "1")
set(MAIL_FLAGS "-DLINUX")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 ${DEBUG}=${DEBUG_LEVEL} ${MAIL_FLAGS}")

set(SOURCE_FILES
        src/main.cpp
        src/Webcam.cpp
        src/Webcam.h
        src/WebcamNotFoundException.cpp
        src/WebcamNotFoundException.h
        src/VideoDisplay.cpp
        src/VideoDisplay.h
        src/App.cpp
        src/App.h
        src/MotionTrack.cpp
        src/MotionTrack.h
        src/FrameOutput.h
        src/FrameOutputFile.cpp
        src/FrameOutputFile.h
        include/base64.cpp
        include/base64.h
        include/CSmtp.cpp
        include/CSmtp.h
        src/FrameOutputMail.cpp
        src/FrameOutputMail.h
        src/MailSender.cpp
        src/MailSender.h)

add_executable(surveillance ${SOURCE_FILES})

target_link_libraries(surveillance ${OpenCV_LIBS})
