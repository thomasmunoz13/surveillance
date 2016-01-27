#include <opencv2/core/core.hpp>
#include "Webcam.h"
#include "VideoDisplay.h"
#include "App.h"

using namespace std;
using namespace cv;

int main() {

    Webcam webcam = Webcam();
    VideoDisplay videoDisplay = VideoDisplay("Video");
    App app = App();

    app.showUntil(webcam, videoDisplay, app.ESC);
    return 0;
}

