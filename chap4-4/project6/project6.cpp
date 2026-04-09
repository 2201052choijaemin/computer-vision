#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
Mat img;
void on_mouse(int event, int x, int y, int flags, void* userdata);
int main()
{
    img = Mat(200, 400, CV_8UC3, Scalar(255, 255, 255));
    namedWindow("img");
    setMouseCallback("img", on_mouse);
    imshow("img", img);
    int key;
    while (true) {
        key = waitKey(10);
        if (key == 'q') break;
    }
    return 0;
}
void on_mouse(int event, int x, int y, int flags, void* userdata)
{
    switch (event) {
    case EVENT_LBUTTONDOWN:
        img = Scalar(0, 0, 255);
        imshow("img", img);
        break;
    case EVENT_RBUTTONDOWN:
        img = Scalar(255, 0, 0);
        imshow("img", img);
        break;
    }
}
