//
// Created by thomas on 28/01/16.
//

#include <iostream>
#include <chrono>
#include "FrameOutputMail.h"

FrameOutputMail::FrameOutputMail(const std::string &destination,
                                 const std::string &from,
                                 const std::string &subject,
                                 const std::string &fileBase,
                                 time_t limit,
                                 MailSender mailSender,
                                 FrameOutputFile outputFile)

        : destination(destination), from(from), subject(subject),
          fileBase(fileBase), limit(limit), mailSender(mailSender),
          outputFile(outputFile)
{}


void FrameOutputMail::save(const cv::Mat frame) {
    std::string fileName = this->outputFile.saveFile(frame);

    if(hasPeriodPassed()){
        sendMail(fileName);
        this->lastMessage = std::time(nullptr);
    }
}

bool FrameOutputMail::hasPeriodPassed() {
    return (this->lastMessage + this->limit) < std::time(nullptr);
}

void FrameOutputMail::sendMail(const std::string fileName) {
    std::stringstream ss;

    std::chrono::time_point<std::chrono::system_clock> start;
    start = std::chrono::system_clock::now();

    std::time_t end_time = std::chrono::system_clock::to_time_t(start);

    ss << "A new movement has been detected at "
    << " at " << std::ctime(&end_time)
    << std::endl;

    this->mailSender.send(this->destination, "A movement has been detected", ss.str(), fileName);
}
