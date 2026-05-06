#include <opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;
Mat src, dst;
int bright = 0;
int mode = 0;
void on_brightness(int pos, void* userdata);
void on_mouse(int event, int x, int y, int flags, void* userdata);
int main(void) {
	src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	if (src.empty()) { cerr << "Image load failed!" << endl; return -1; }
	dst = Mat(src.rows, src.cols, src.type());
	namedWindow("src");
	imshow("src", src);
	createTrackbar("mode", "src", 0, 1, on_brightness);
	setMouseCallback("src", on_mouse);
	waitKey();
	return 0;
}
void on_brightness(int pos, void* userdata) {
	mode = pos;
}
void on_mouse(int event, int x, int y, int flags, void* userdata) {

	switch (event) {
	case EVENT_LBUTTONDOWN:
		if (mode == 0) {
			bright += 10;
		}
		else if (mode == 1) {
			bright -= 10;
		}
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
