#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {
    Mat img = imread("lenna.bmp", IMREAD_COLOR);
    if (img.empty()) {
        cout << "이미지를 불러올 수 없습니다." << endl;
        return -1;
    }
    Point xy[] = { Point(50, 50), Point(100, 100), Point(150, 150) };
    for (int i = 0; i < 3; i++) {
        int x = xy[i].x;
        int y = xy[i].y;
        Vec3b pixel = img.at<Vec3b>(y, x);
        int B = pixel[0];
        int G = pixel[1];
        int R = pixel[2];
        cout << "좌표(" << x << "," << y << ")의 화소값(B,R,G) :" << B << "," << G << "," << R << endl;
    }
    return 0;
}