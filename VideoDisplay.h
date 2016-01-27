//
// Created by thomas on 27/01/16.
//

#ifndef SURVEILLANCE_VIDEODISPLAY_H
#define SURVEILLANCE_VIDEODISPLAY_H

#include <opencv2/core/types_c.h>
#include <string>

class VideoDisplay {
private :
    char * windowName;

public :
    VideoDisplay(char * name);

    void showFrame(IplImage * frame);
};


#endif //SURVEILLANCE_VIDEODISPLAY_H
