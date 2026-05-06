#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

Mat src, dst;

void on_mouse(int event, int x, int y, int flags, void* userdata);
void increase_pixel(int y, int x);

int main(void) {
    src = imread("lenna.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    dst = Mat(src.rows, src.cols, src.type());
    for (int j = 0; j < src.rows; j++) {
        for (int i = 0; i < src.cols; i++) {
            dst.at<uchar>(j, i) = src.at<uchar>(j, i);
        }
    }

    namedWindow("src");
    imshow("src", dst);

    setMouseCallback("src", on_mouse);

    waitKey();
    return 0;
}

void increase_pixel(int y, int x) {
    if (x < 0 || x >= dst.cols || y < 0 || y >= dst.rows)
        return;

    int value = dst.at<uchar>(y, x) + 100;
    dst.at<uchar>(y, x) = saturate_cast<uchar>(value);
}

void on_mouse(int event, int x, int y, int flags, void* userdata) {

    switch (event) {
    case EVENT_MOUSEMOVE:
        if (flags & EVENT_FLAG_LBUTTON) {
            increase_pixel(y, x);      
            increase_pixel(y - 1, x);  
            increase_pixel(y + 1, x);  
            increase_pixel(y, x - 1);   
            increase_pixel(y, x + 1);   

            imshow("src", dst);
        }
        break;
    }
}
