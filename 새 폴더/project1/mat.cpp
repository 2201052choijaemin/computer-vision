#include <opencv2/opencv.hpp>  // OpenCV 라이브러리 포함
#include <iostream>            // 입출력을 위한 iostream 포함
using namespace cv;            // cv 네임스페이스 사용
using namespace std;           // std 네임스페이스 사용

int main()
{
    float data1[] = { 3.5, 2.1, -1.5, -6.5 };   // 2x2 행렬에 사용할 데이터 배열
    Mat mat1(2, 2, CV_32FC1, data1);            // 2행 2열, float형(32비트) 1채널 행렬 생성

    float data2[] = { 0, 2, -1, 5, 10, 8, 6, -7, 9 }; // 3x3 행렬 데이터
    Mat mat2(3, 3, CV_32FC1, data2);                  // 3행 3열 행렬 생성

    float data3[] = { 1, 2, 3, 4 };           // 1x4 행렬 데이터 (행 벡터)
    Mat mat3(1, 4, CV_32FC1, data3);          // 1행 4열 행렬 생성

    float data4[] = { 5, 6, 7, 8 };           // 4x1 행렬 데이터 (열 벡터)
    Mat mat4(4, 1, CV_32FC1, data4);          // 4행 1열 행렬 생성

    cout << "mat1 =" << endl << mat1 << endl; // mat1 출력
    cout << "mat2 =" << endl << mat2 << endl; // mat2 출력
    cout << "mat3 =" << endl << mat3 << endl; // mat3 출력
    cout << "mat4 =" << endl << mat4 << endl; // mat4 출력

    return 0; // 프로그램 정상 종료
}


