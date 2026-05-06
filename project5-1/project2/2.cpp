#include <opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;
Mat src;
Point ptol;
void on_mouse(int event, int x, int y, int flags, void* userdata);
int main(void) {
	src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	if (src.empty()) { cerr << "Image load failed!" << endl; return -1; }
	imshow("src", src);
	setMouseCallback("src", on_mouse);
	waitKey();
	return 0;
}
void on_mouse(int event, int x, int y, int flags, void* userdata) {
	switch (event) {
	case EVENT_LBUTTONDOWN:
		ptol = Point(x, y);
		break;
	case EVENT_LBUTTONUP:
		Mat value = src(Rect(ptol, Point(x, y)));
		value += Scalar(100);
		imshow("src", src);
		break;
	}
}
