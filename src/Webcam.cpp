/**
 * @author Thomas Munoz
 */

#include "Webcam.h"

cv::Mat Webcam::getCurrentFrame() {
    cv::Mat frame;
    this->webcam.read(frame);
    return frame;
}

Webcam::Webcam() throw(WebcamNotFoundException) {
    init();
}

bool Webcam::init() throw(WebcamNotFoundException){
    this->webcam.open(0);
    if(!this->webcam.isOpened()) throw new WebcamNotFoundException();
}

void Webcam::close() {
    this->webcam.release();
}
