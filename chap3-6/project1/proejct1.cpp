#include <opencv2/opencv.hpp>   // OpenCV 라이브러리 사용
#include<iostream>              // 입출력 사용
using namespace cv;
using namespace std;

int main()
{
    Mat img1 = imread("img.bmp");   // img.bmp 이미지를 읽어서 Mat 객체에 저장

    cout << "Width: " << img1.cols << endl;     // 이미지의 가로 크기 (열 수)
    cout << "Height: " << img1.rows << endl;    // 이미지의 세로 크기 (행 수)
    cout << "Channels: " << img1.channels() << endl; // 채널 수 (1: 흑백, 3: 컬러)

    if (img1.type() == CV_8UC1)     // 8비트 unsigned, 채널 1개 (흑백 이미지)
        cout << "CV_8UC1" << endl;
    else if (img1.type() == CV_8UC3) // 8비트 unsigned, 채널 3개 (컬러 이미지 BGR)
        cout << "CV_8UC3" << endl;

    float data[] = { 2.f, 1.414f, 3.f, 1.732f }; // float형 배열 생성

    Mat mat1(2, 2, CV_32FC1, data); // 2x2 크기, float형(32비트), 1채널 행렬 생성 (data 배열 사용)

    cout << "mat1:\n" << mat1 << endl; // 행렬 내용 출력

    return 0;
}