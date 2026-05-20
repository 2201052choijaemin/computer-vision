#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
    Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }
    imshow("src", src);
    int alphaArr[5] = { 10, 20, 30, 40, 50 };
    for (int i = 0; i < 5; i++)
    {
        Mat blurred;
        blur(src, blurred, Size(5, 5));
        float alpha = alphaArr[i] / 10.0f;
        Mat dst = (1 + alpha) * src - alpha * blurred;
        String desc = format("alpha : %d", alphaArr[i]);
        putText(dst, desc, Point(10, 30),
            FONT_HERSHEY_SIMPLEX, 1.0,
            Scalar(255), 1, LINE_AA);
        String winName = format("dst %d", alphaArr[i]);
        imshow(winName, dst);
    }
    waitKey();
    return 0;
}
