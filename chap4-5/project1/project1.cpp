#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
Mat img;
int po;
void on_tackerbar(int pos, void* userdata);
int main(void)
{
	img = imread("lenna.bmp", IMREAD_COLOR);
	if (img.empty()) { cerr << "image load failed!" << endl; return -1; }
	namedWindow("img");
	createTrackbar("level", "img", 0, 100, on_tackerbar);
	int key;
	while (true) {
		imshow("img", img);
		key = waitKey(10);
		if (key == 'q') break;
	}
	return 0;
}
void on_tackerbar(int pos, void* userdata) {
	po = pos;
	cout << "트랙바 위치:" << po << endl;
	circle(img, Point(img.cols / 2, img.rows / 2), po, Scalar(0, 255, 0), 5);
}
