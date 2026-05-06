#include <opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;
Mat src, dst;
int bright = 0;
void on_mouse(int event, int x, int y, int flags, void* userdata);
int main(void) {
	src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	if (src.empty()) { cerr << "Image load failed!" << endl; return -1; }
	dst = Mat(src.rows, src.cols, src.type());
	imshow("src", src);
	setMouseCallback("src", on_mouse);
	waitKey();
	return 0;
}
void on_mouse(int event, int x, int y, int flags, void* userdata) {
	switch (event) {
	case EVENT_LBUTTONDOWN:
		bright += 10;
		break;
	case EVENT_RBUTTONDOWN:
		bright -= 10;
		break;
	}
	for (int j = 0; j < src.rows; j++) {
		for (int i = 0; i < src.cols; i++) {
			int value = src.at<uchar>(j, i) + bright;
			dst.at<uchar>(j, i) = saturate_cast<uchar>(value);
		}
	}
	imshow("src", dst);
}
