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

    int SENSITIVITY;

    Webcam webcam;

    cv::Mat lastFrame;


#if DEBUG == 1
    void drawContour(cv::Mat & frame, std::vector<std::vector<cv::Point>> contours);
#endif

public :
    MotionTrack(Webcam webcam);

    bool detect();

    const cv::Mat & getLastFrame();
    
    void setSentivity(int);
};



#endif //SURVEILLANCE_MOTIONTRACK_H
