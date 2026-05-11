#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main(void) {
    Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }
    float alpha = 1.f;
    Mat dst(src.rows, src.cols, src.type());
    for (int j = 0; j < src.rows; j++) {
        for (int i = 0; i < src.cols; i++) {
            uchar p = src.at<uchar>(j, i);
            int value = (p + p - 128) * alpha;
            if (value < 0)
                value = 0;
            else if (value > 255)
                value = 255;
            dst.at<uchar>(j, i) = (uchar)value;
        }
    }
    imshow("src", src);
    imshow("dst", dst);
    waitKey();
    return 0;
}
