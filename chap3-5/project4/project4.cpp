#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
    Mat img(400, 400, CV_8UC1, Scalar(255));
    for (int x = 0; x < img.cols; x++) {
        int y = ((1.0 / 400) * x * x);
        if (y >= 0 && y < img.rows) {
            img.at<uchar>(y, x) = 0;
        }
    }
    imshow("img", img);
    waitKey(0);
    return 0;
}
