/**
 * @author Thomas Munoz
 */

#ifndef SURVEILLANCE_MOTIONTRACK_H
#define SURVEILLANCE_MOTIONTRACK_H

#include "Webcam.h"

#if DEBUG == 1
#include "VideoDisplay.h"
#endif
;
class MotionTrack {

private :
    enum {
        SENSITIVITY = 70,
        BLUR = 10
    };

    Webcam webcam;

    void save(cv::Mat frame);

#if DEBUG == 1
    void drawContour(cv::Mat & frame, std::vector<std::vector<cv::Point>> contours);
#endif

public :
    MotionTrack(Webcam webcam);

    cv::Mat detect();
};


#endif //SURVEILLANCE_MOTIONTRACK_H
