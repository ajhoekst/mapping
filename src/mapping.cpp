#include "opencv2/opencv.hpp"
#include <iostream>
#include <chrono>
#include <thread>


using namespace std;
using namespace cv;

int main( int argc, const char** argv )
{
    float fps;
    const char *fileOut;
    int frameNumber = 0;
    Size s;
    chrono::high_resolution_clock::time_point tic, toc;
    chrono::milliseconds ms;
    Mat frame;
    
    switch (argc)
    {
        case 2:
            ms = chrono::milliseconds(100);
            fps = 10;
            fileOut = argv[1];
            break;
        case 3:
            ms = chrono::milliseconds((int) (1000 / stof(argv[1])));
            fps = 1000. / ms.count();
            fileOut = argv[2];
            break;
        default:
            cout << "Usage: mapping [fps] fileOut" << endl;
            return -1;
    }
    
    VideoCapture cap(0);
    if (!cap.isOpened())
    {
        cout << "Count not open the camera" << endl;
        return -1;
    }
    else
    {
       s = Size((int) cap.get(CV_CAP_PROP_FRAME_WIDTH),
                (int) cap.get(CV_CAP_PROP_FRAME_HEIGHT));
    }
    cout << "Output filename: " << fileOut << endl;
    cout << "Frame size: " << s << endl;
    cout << "Frame rate: " << fps << endl;
    
    namedWindow("MyWindow", CV_WINDOW_AUTOSIZE);
    
    tic = chrono::high_resolution_clock::now();
    while (1)
    {
        // Capture frames as close together as possible
        //cap.grab();
        //cap2.grab();
        
        // processing
        //cap.retrieve(frame);
        cap >> frame;
        imshow("MyWindow", frame);
        
        toc = chrono::high_resolution_clock::now();
        this_thread::sleep_for(ms - (toc - tic));
        cout << chrono::duration_cast<chrono::milliseconds>(ms - (toc - tic)).count() << endl;
        tic = toc;
        //if (duration > 0)
        //{
        //}
        //else
        //{
        //    cout << "Overflow!" << endl;
        //}
        
        // Processing
        //if (!frame.empty() && !prevFrame.empty())
        //{
        //    absdiff(prevFrame, frame, toDisp);
        //    imshow("MyWindow", frame);
        //}
        //prevFrame = frame;
    }
    
    destroyWindow("MyWindow");
    
    return 0;
}