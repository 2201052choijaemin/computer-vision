#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
void onMouse(int event, int x, int y, int flags, void* userdata);
int main() {
    Mat img = imread("lenna.bmp", IMREAD_COLOR);

    if (img.empty()) {
        cerr << "lmage load failed!" << endl;
        return -1;
    }
    namedWindow("img");
    imshow("img", img);
    setMouseCallback("img", onMouse);
    while (true)
    {
        if (waitKey(1) == 'q') break;
    }
    return 0;
}
int count_down = 0;
int count_up = 0;
int count_move = 0;
void onMouse(int event, int x, int y, int flags, void* userdata)
{
    switch (event) {
    case EVENT_LBUTTONDOWN:
        count_down++;
        cout << "EVENT_LBUTTONDOWN: " << count_down << endl;
        break;
    case EVENT_LBUTTONUP:
        count_up++;
        cout << "EVENT_LBUTTONUP: " << count_up << endl;
        break;
    case EVENT_MOUSEMOVE:
        count_move++;
        cout << "EVENT_MOUSEMOVE: " << count_move << endl;
        break;
    default:
        break;
    }
}
