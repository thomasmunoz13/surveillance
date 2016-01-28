/**
 * @author Thomas Munoz
 */

#ifndef SURVEILLANCE_VIDEODISPLAY_H
#define SURVEILLANCE_VIDEODISPLAY_H

#include <opencv2/core/types_c.h>
#include <opencv2/core/core.hpp>
#include <string>

class VideoDisplay {
private :
    char * windowName;

public :
    VideoDisplay(char * name);

    void showFrame(const cv::Mat & mat);
};


#endif //SURVEILLANCE_VIDEODISPLAY_H
