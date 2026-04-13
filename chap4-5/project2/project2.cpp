#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
Mat img;
int tracker;
Point ptol;
void on_mouse(int event, int x, int y, int flags, void* userdata);
void on_tackerbar(int pos, void* userdata);
int main(void)
{
    img = Mat(500, 500, CV_8UC3, Scalar(255, 255, 255));
    if (img.empty()) { cerr << "image loade failed!" << endl; return -1; }
    namedWindow("img");
    setMouseCallback("img", on_mouse);
    createTrackbar("level", "img", 0, 3, on_tackerbar);
    imshow("img", img);
    while (true) {
        if (waitKey(10) == 'q') break;
    }
    return 0;
}
void on_mouse(int event, int x, int y, int flags, void* userdata) {
    Scalar color;
    static Point ptol;
    if (tracker == 0) color = Scalar(255, 0, 0);
    else if (tracker == 1) color  =  Scalar(0, 255, 0);
    else if (tracker == 2) color = Scalar(0, 0, 255);
    else if (tracker == 3) color = Scalar(255, 255, 255);
    switch (event) {
    case EVENT_LBUTTONDOWN:
        ptol = Point(x,y);
        break;
    case EVENT_LBUTTONUP:
        if (tracker == 3) {
            rectangle(img, Rect(ptol, Point(x, y)), color, -1);
        }
        else {
            rectangle(img, Rect(ptol, Point(x, y)), color);
            ptol = Point(x, y);
        }
        imshow("img", img);
    }
}
void on_tackerbar(int pos, void* userdata) {
    tracker = pos;
}
