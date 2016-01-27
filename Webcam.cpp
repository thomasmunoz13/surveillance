//
// Created by thomas on 27/01/16.
//

#include "Webcam.h"

IplImage *Webcam::getCurrentFrame() {
    return cvQueryFrame(this->webcam);
}

Webcam::Webcam() throw(WebcamNotFoundException) {
    init();
}

bool Webcam::init() throw(WebcamNotFoundException){
    this->webcam = cvCaptureFromCAM(0);
    if(!this->webcam) throw new WebcamNotFoundException();
}
