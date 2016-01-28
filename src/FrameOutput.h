/**
 * @author Thomas Munoz
 */
#ifndef SURVEILLANCE_FRAMEOUTPUT_H
#define SURVEILLANCE_FRAMEOUTPUT_H

#include <opencv2/core/core.hpp>

class FrameOutput {
public :
    virtual void save(const cv::Mat frame) = 0;
};

#endif //SURVEILLANCE_FRAMEOUTPUT_H
