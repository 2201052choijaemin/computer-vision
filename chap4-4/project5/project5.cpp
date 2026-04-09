#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
void event_handler(int event, int x, int y, int flags, void* userdata);
Mat img;
int main(void)
{
    img = imread("lenna.bmp", IMREAD_COLOR);
    if (img.empty()) { cerr << "Image load failed!" << endl; return -1; }
    namedWindow("img");
    setMouseCallback("img", event_handler);
    int key;
    while (true) {
        imshow("img", img);
        key = waitKey(10);
        if (key == 'q') break;
    }
    return 0;
}
void event_handler(int event, int x, int y, int flags, void* userdata)
{
    static Point ptOld;
    switch (event) {
    case EVENT_LBUTTONDOWN:
        ptOld = Point(x, y);
        break;
    case EVENT_LBUTTONUP:
    {
        Rect roi(ptOld, Point(x,y));
        if (roi.width > 0 && roi.height > 0) {
            if (roi.height > 0) {
                Mat cropped = img(roi);
                imshow("cropped", cropped);
            }
        }
        break;
    }
    default:
        break;
    }
}
