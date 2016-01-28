/**
 * @author Thomas Munoz
 */

#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "VideoDisplay.h"

using namespace cv;

VideoDisplay::VideoDisplay(char * name)
        : windowName(name)
{
    cvNamedWindow(name);
}

void VideoDisplay::showFrame(const Mat & mat) {
    imshow(this->windowName, mat);
}
