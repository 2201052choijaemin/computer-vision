#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
    Mat img = imread("lenna.bmp", IMREAD_GRAYSCALE);
    if (img.empty()) return -1;
    int line_x[3] = { img.cols / 4, img.cols / 2, (img.cols * 3) / 4 };
    int line_y[3] = { img.rows / 4, img.rows / 2, (img.rows * 3) / 4 };
    for (int i = 0; i < 3; i++) {
        int x = line_x[i];
        for (int y = 0; y < img.rows; y++) {
            img.at<uchar>(y, x) = 255;
        }
    }
    for (int i = 0; i < 3; i++) {
        int y = line_y[i];
        for (int x = 0; x < img.cols; x++) {
            img.at<uchar>(y, x) = 255;
        }
    }
    imshow("Line", img);
    waitKey(0);
    return 0;
}
