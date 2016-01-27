/**
 * @author Thomas Munoz
 */

#include <iostream>
#include "App.h"
#include "MotionTrack.h"

void App::showUntil(Webcam webcam, VideoDisplay videoDisplay, const char key) {
    MotionTrack motionTrack = MotionTrack(webcam);

    while(true) {
         if((char) cvWaitKey(40) == key) {
             webcam.close();
             break;
         }

        videoDisplay.showFrame(motionTrack.detect());
    }
}
