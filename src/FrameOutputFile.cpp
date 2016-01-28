/**
 * @author Thomas Munoz
 */

#include <chrono>
#include <opencv2/highgui/highgui.hpp>
#include "FrameOutputFile.h"


FrameOutputFile::FrameOutputFile(std::string fileBase)
    : fileBase(fileBase)
{}

void FrameOutputFile::save(const cv::Mat frame) {
    saveFile(frame);
}

std::string FrameOutputFile::saveFile(const cv::Mat frame) {
    std::stringstream ss;

    std::chrono::time_point<std::chrono::system_clock> start;
    start = std::chrono::system_clock::now();

    std::time_t end_time = std::chrono::system_clock::to_time_t(start);

    // Use of random to avoid same filename for the same second
    ss << this->fileBase << std::ctime(&end_time) << '-' << rand() % 1000 + 0 << ".jpg";

    cv::imwrite(ss.str(), frame);

    return ss.str();
}
