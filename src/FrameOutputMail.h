/**
 * @author Thomas Munoz
 */

#ifndef SURVEILLANCE_FRAMEOUTPUTMAIL_H
#define SURVEILLANCE_FRAMEOUTPUTMAIL_H


#include "FrameOutput.h"
#include "MailSender.h"
#include "FrameOutputFile.h"
#include <ctime>

class FrameOutputMail : public FrameOutput {
private :
    std::string destination;
    std::string from;
    std::string subject;
    std::string fileBase;
    std::time_t lastMessage = 0;
    std::time_t limit;

    MailSender mailSender;
    FrameOutputFile outputFile;

    bool hasPeriodPassed();
    void sendMail(const std::string fileName);
public:

    FrameOutputMail(const std::string &destination, const std::string &from, const std::string &subject,
                    const std::string &fileBase, time_t limit, MailSender mailSender, FrameOutputFile outputFile);

    virtual void save(const cv::Mat frame);
};


#endif //SURVEILLANCE_FRAMEOUTPUTMAIL_H
