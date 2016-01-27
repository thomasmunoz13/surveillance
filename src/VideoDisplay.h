//
// Created by thomas on 27/01/16.
//

#ifndef SURVEILLANCE_VIDEODISPLAY_H
#define SURVEILLANCE_VIDEODISPLAY_H

#include <opencv2/core/types_c.h>
#include <string>
#include <opencv2/core/core.hpp>

class VideoDisplay {
private :
    char * windowName;

public :
    VideoDisplay(char * name);

    void showFrame(cv::Mat mat);
};


#endif //SURVEILLANCE_VIDEODISPLAY_H
