#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;

int main( int argc, const char** argv )
{
    VideoCapture cap(0);
    if (!cap.isOpened()) return -1;
    
    namedWindow("MyWindow", CV_WINDOW_AUTOSIZE);
    
    Mat frame;
    while (1)
    {
        cap >> frame;
        if (!frame.empty()) imshow("MyWindow", frame);
        if (waitKey(1) >= 0) break;
    }
    
    destroyWindow("MyWindow");

    return 0;
}