#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
Mat img;
void onMouse(int event, int x, int y, int flags, void* userdata);
int main() {
    img = imread("lenna.bmp", IMREAD_COLOR);
    if (img.empty()) {
        cerr << "lmage load failed!" << endl;
        return -1;
    }
    namedWindow("img");
    setMouseCallback("img", onMouse);
    imshow("img", img);
    int key;
    while (true) {
        key = waitKey(10);
        if (key == 'q') break;
    }
    return 0;
}
void onMouse(int event, int x, int y, int flags, void* userdata)
{
    switch (event) {
    case EVENT_LBUTTONDOWN:
    {
        cout << "좌표: " << Point(x, y);
        Vec3b color = img.at<Vec3b>(y, x);
        cout << ", 화소값(B, R, G): " << color << endl;
        break;
    }
    default:
        break;
    }
}
