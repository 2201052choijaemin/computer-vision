#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
    Mat img = imread("lenna.bmp", IMREAD_COLOR);
    if (img.empty()) return -1;
    int line_x[3] = { img.cols / 4, img.cols / 2, (img.cols * 3) / 4 };
    int line_y[3] = { img.rows / 4, img.rows / 2, (img.rows * 3) / 4 };
    for (int y = 0; y < img.rows; y++) {
        for (int i = 0; i < 3; i++) {
            int x = line_x[i];
            img.at<Vec3b>(y, x)[0] = 255;
            img.at<Vec3b>(y, x)[1] = 255;
            img.at<Vec3b>(y, x)[2] = 255;
        }
    }
    for (int x = 0; x < img.cols; x++) {
        for (int i = 0; i < 3; i++) {
            int y = line_y[i];
            img.at<Vec3b>(y, x)[0] = 255;
            img.at<Vec3b>(y, x)[1] = 255;
            img.at<Vec3b>(y, x)[2] = 255;
        }
    }
    imshow("Grid 4x4", img);
    waitKey(0);
    return 0;
}