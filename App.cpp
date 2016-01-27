//
// Created by thomas on 27/01/16.
//

#include <iostream>
#include "App.h"

void App::showUntil(Webcam webcam, VideoDisplay videoDisplay, const char key) {
    while(true) {
         if((char) cvWaitKey(40) == key) break;

        videoDisplay.showFrame(webcam.getCurrentFrame());
    }
}
