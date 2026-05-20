#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>

using namespace cv;
using namespace std;

int main()
{
    Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }
    Mat dst;
    int ksizeArr[3] = { 3, 10, 30 };
    for (int i = 0; i < 3; i++) {
        int ksize = ksizeArr[i];
        auto startTime = chrono::steady_clock::now();
        blur(src, dst, Size(ksize, ksize));
        auto endTime = chrono::steady_clock::now();
        float totalTime =
            chrono::duration<float, milli>(endTime - startTime).count();
        cout << "Kernel Size: "
            << ksize << "x" << ksize
            << " -> Time: "
            << totalTime << " ms" << endl;
        String desc = format("Mean: %dx%d", ksize, ksize);
        putText(dst, desc, Point(10, 30),FONT_HERSHEY_SIMPLEX,1.0, Scalar(255), 1, LINE_AA);
        imshow("dst", dst);
        waitKey();
    }
    return 0;
}
