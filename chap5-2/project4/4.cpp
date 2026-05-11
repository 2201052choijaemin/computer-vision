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
    Scalar avg = mean(src);
    float m = (float)avg[0];
    float alpha = 1.0f;
    Mat dst = (src + src - m) * alpha;
    imshow("src", src);
    imshow("dst", dst);
    cout << "Mean intensity = " << m << endl;
    waitKey();
    return 0;
}
