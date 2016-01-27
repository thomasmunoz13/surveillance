//
// Created by thomas on 27/01/16.
//

#ifndef SURVEILLANCE_WEBCAM_H
#define SURVEILLANCE_WEBCAM_H


#include <opencv2/highgui/highgui_c.h>
#include "WebcamNotFoundException.h"

class Webcam {
    CvCapture * webcam;

public :
    Webcam() throw(WebcamNotFoundException);

    IplImage * getCurrentFrame();

private :

    bool init() throw(WebcamNotFoundException);
};


#endif //SURVEILLANCE_WEBCAM_H
