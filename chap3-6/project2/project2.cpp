#include <opencv2/opencv.hpp>   // OpenCV 라이브러리
#include <iostream>             // 입출력
using namespace cv;
using namespace std;

int main()
{
    float a[] = { 1, 3, -4, 2 };        // 행렬 A에 사용할 데이터
    Mat A(2, 2, CV_32FC1, a);           // 2x2 크기, float형(32비트), 1채널 행렬 A 생성

    float b[] = { 2, 3, 0, 5 };         // 행렬 B 데이터
    Mat B(2, 2, CV_32FC1, b);           // 행렬 B 생성

    float c[] = { -2, -2, -2, -3 };     // 행렬 C 데이터
    Mat C(2, 2, CV_32FC1, c);           // 행렬 C 생성

    Mat B_inv = B.inv();                // 행렬 B의 역행렬 계산 (B⁻¹)

    Mat X = 3 * A + B_inv + 10 * C - 5; // 행렬 연산 수행
    // 3*A → A의 각 원소에 3을 곱함
    // B_inv → B의 역행렬
    // 10*C → C의 각 원소에 10을 곱함
    // -5 → 모든 원소에 5를 빼는 스칼라 연산

    cout << "X = \n" << X << endl;      // 결과 행렬 출력

    return 0;
}