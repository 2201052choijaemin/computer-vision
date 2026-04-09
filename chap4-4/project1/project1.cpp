#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
    Mat img = imread("lenna.bmp", IMREAD_COLOR);

    if (img.empty()) {
        cout << "lmage load failed!" << endl;
        return -1;
    }
    while (true)
    {
        imshow("Lenna", img);
        char key = waitKey(0);
        if (key == 'q') {
            break;
        }
        else if (key == 'l') {
            line(img, Point(100, 400), Point(400, 400), Scalar(255, 255, 255), 2);
            imshow("Lenna", img);
        }
        else if (key == 'c') {
            circle(img, Point(270, 270), 100, Scalar(0, 0, 255), 2);
            imshow("Lenna", img);
        }
        else if (key == 't') {
            putText(img, "Hello, Lenna", Point(150, 150),
                FONT_HERSHEY_SIMPLEX, 1.0, Scalar(0, 255, 255), 2);
            imshow("Lenna", img);
        }
    }
    return 0;
}
