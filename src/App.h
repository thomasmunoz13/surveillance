//
// Created by thomas on 27/01/16.
//

#ifndef SURVEILLANCE_APP_H
#define SURVEILLANCE_APP_H

#include "Webcam.h"
#include "VideoDisplay.h"

class App {

public :
    enum {
        ESC = 27
    };

    void showUntil(Webcam webcam, VideoDisplay videoDisplay, const char key);
};


#endif //SURVEILLANCE_APP_H
