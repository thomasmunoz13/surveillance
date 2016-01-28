/**
 * @author Thomas Munoz
 */

#include "App.h"
#include "MotionTrack.h"

App::App(FrameOutput * output)
        : output(output)
{}

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
#endif

        if(motionTrack.detect()) this->output->save(motionTrack.getLastFrame());

#if DEBUG == 1
        videoDisplay.showFrame(motionTrack.getLastFrame());
#endif
    }
}