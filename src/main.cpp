#include <opencv2/core/core.hpp>
#include "Webcam.h"

#if DEBUG == 1
#include "VideoDisplay.h"
#endif

#include "App.h"
#include "FrameOutputFile.h"

using namespace std;
using namespace cv;

int main() {
    srand (time(NULL));

    Webcam webcam = Webcam();
    FrameOutputFile outputFile = FrameOutputFile("images/");
    App app = App(&outputFile);

#if DEBUG == 1
    VideoDisplay videoDisplay = VideoDisplay((char *) "Video");
    app.showUntil(webcam, videoDisplay, app.ESC);
#else
    app.showUntil(webcam, app.ESC);
#endif
    return 0;
}

