#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(void)
{
    Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);

    if (src.empty()) {
        cerr << "Image load error!" << endl;
        return -1;
    }
    float data[] = {1/9.f,1 / 9.f, 1 / 9.f, 1 / 9.f, 1 / 9.f, 1 / 9.f, 1 / 9.f, 1 / 9.f, 1 / 9.f};

    Mat mask(3, 3, CV_32FC1, data);
    Mat dst;
    filter2D(src, dst, -1, mask, Point(-1, -1), 0);

    imshow("src", src);
    imshow("dst", dst);

    waitKey(0);
    return 0;
}
