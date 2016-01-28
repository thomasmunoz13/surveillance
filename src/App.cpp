/**
 * @author Thomas Munoz
 */

#include "App.h"
#include "MotionTrack.h"

#if DEBUG == 1
void App::showUntil(Webcam webcam, VideoDisplay videoDisplay, const char key)
#else
void App::showUntil(Webcam webcam, const char key)
#endif
{

    MotionTrack motionTrack = MotionTrack(webcam);
    while(true) {
#if DEBUG == 1
         if((char)cvWaitKey(40) == key) {
             webcam.close();
             break;
         }


        videoDisplay.showFrame(motionTrack.detect());
#else
        motionTrack.detect();
#endif
    }
}