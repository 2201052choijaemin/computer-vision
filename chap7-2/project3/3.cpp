#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main(void)
{
    Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) { cerr << "Image load failed!" << endl; return -1; }
    imshow("src", src);
    float data[] = { 1 / 273.f, 4 / 273.f, 7 / 273.f, 4 / 273.f, 1 / 273.f,
                     4 / 273.f, 16 / 273.f, 26 / 273.f, 16 / 273.f, 4 / 273.f,
                     7 / 273.f, 26 / 273.f, 41 / 273.f, 26 / 273.f, 7 / 273.f,
                     4 / 273.f, 16 / 273.f, 26 / 273.f, 16 / 273.f, 4 / 273.f,
                     1 / 273.f, 4 / 273.f, 7 / 273.f, 4 / 273.f, 1 / 273.f };
    Mat ksize(5, 5, CV_32F, data);
    Mat dst1, dst2;
    filter2D(src, dst1, -1, ksize, Point(-1, -1), 0);
    GaussianBlur(src, dst2, Size(5, 5), 0);
    imshow("dst1", dst1);
    imshow("dst2", dst2);
    waitKey();
    return 0;
}
