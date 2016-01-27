/**
 * @author Thomas Munoz
 */

#ifndef SURVEILLANCE_WEBCAMNOTFOUNDEXCEPTION_H
#define SURVEILLANCE_WEBCAMNOTFOUNDEXCEPTION_H


#include <exception>

class WebcamNotFoundException : public std::exception
{
    virtual const char * what();
};


#endif //SURVEILLANCE_WEBCAMNOTFOUNDEXCEPTION_H
