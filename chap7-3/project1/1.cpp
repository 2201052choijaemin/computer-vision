#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
    Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cout << "영상 파일을 열 수 없습니다." << endl;
        return -1;
    }
    float weights[9] = {
        -1, -1, -1,
        -1,  9, -1,
        -1, -1, -1
    };
    Mat mask(3, 3, CV_32F, weights);
    imshow("Original", src);
    Mat prev = src;
    Mat dst;
    for (int i = 1; i <= 5; i++)
    {
        filter2D(prev, dst, -1, mask);
        string winName = "Sharpen x " + to_string(i);
        imshow(winName, dst);
        prev = dst;
    }
    waitKey();
    return 0;
}
