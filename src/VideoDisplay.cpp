//
// Created by thomas on 27/01/16.
//

#include <opencv2/highgui/highgui_c.h>
#include "VideoDisplay.h"

VideoDisplay::VideoDisplay(char * name)
        : windowName(name)
{
    cvNamedWindow(name);
}

void VideoDisplay::showFrame(IplImage * frame) {
    cvShowImage(this->windowName, frame);
}
