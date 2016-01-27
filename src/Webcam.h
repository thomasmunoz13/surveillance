/**
 * @author Thomas Munoz
 */

#ifndef SURVEILLANCE_WEBCAM_H
#define SURVEILLANCE_WEBCAM_H



#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "WebcamNotFoundException.h"

class Webcam {
    cv::VideoCapture webcam;

public :
    Webcam() throw(WebcamNotFoundException);

    cv::Mat getCurrentFrame();

    void close();
private :

    bool init() throw(WebcamNotFoundException);
};


#endif //SURVEILLANCE_WEBCAM_H