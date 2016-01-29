#include <opencv2/core/core.hpp>
#include "Webcam.h"

#if DEBUG == 1
#include "VideoDisplay.h"
#endif

#include "App.h"
#include "FrameOutputFile.h"
#include "FrameOutputMail.h"

using namespace std;
using namespace cv;

int main() {
    srand (time(NULL));

    Webcam webcam = Webcam();
    FrameOutputFile outputFile = FrameOutputFile("images/");
    MailSender mailSender = MailSender("ssl0.ovh.net",
                                       "contact@thomasmunoz.fr",
                                       "***",
                                       "Thomas Munoz",
                                       "contact@thomasmunoz.fr",
                                       587);

    FrameOutputMail outputMail = FrameOutputMail("thomas.munoz30@gmail.com",
                                                 "contact@thomasmunoz.fr",
                                                 "A new movement has been detected",
                                                 60,
                                                 mailSender,
                                                 outputFile);

    App app = App(&outputMail);

#if DEBUG == 1
    VideoDisplay videoDisplay = VideoDisplay((char *) "Video");
    app.showUntil(webcam, videoDisplay, app.ESC);
#else
    app.showUntil(webcam, app.ESC);
#endif
    return 0;
}

