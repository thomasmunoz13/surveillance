/**
 * @author Thomas Munoz
 */

#include <chrono>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include "FrameOutputFile.h"


FrameOutputFile::FrameOutputFile(std::string fileBase)
    : fileBase(fileBase)
{}

void FrameOutputFile::save(const cv::Mat frame) {
    saveFile(frame);
}

std::string FrameOutputFile::saveFile(const cv::Mat frame) {
    std::chrono::time_point<std::chrono::system_clock> start;
    start = std::chrono::system_clock::now();

    std::time_t end_time = std::chrono::system_clock::to_time_t(start);

    std::string file = (std::string) (this->fileBase + std::string(std::ctime(&end_time)) + std::string(".jpg"));

    // Remove '\n' in file name caused by ctime()
    file.erase(std::remove(file.begin(), file.end(), '\n'), file.end());

    cv::imwrite(file, frame);

    return file;
}
