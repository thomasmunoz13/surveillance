/**
 * @author Thomas Munoz
 */
#ifndef SURVEILLANCE_FRAMEOUTPUTFILE_H
#define SURVEILLANCE_FRAMEOUTPUTFILE_H

#pragma once

#include "FrameOutput.h"

class FrameOutputFile : public FrameOutput {
private:
    std::string fileBase;

public:
    FrameOutputFile(std::string fileBase);

    virtual void save(const cv::Mat frame);

    std::string saveFile(const cv::Mat frame);
};


#endif //SURVEILLANCE_FRAMEOUTPUTFILE_H
