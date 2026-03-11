#include "opencv2/opencv.hpp"   // OpenCV 라이브러리 헤더
#include <iostream>             // 콘솔 입출력 사용

using namespace cv;             // OpenCV 함수, 클래스 사용
using namespace std;            // 표준 C++ 함수, 객체 사용

int main()
{
    // OpenCV 버전 출력
    cout << "Hello OpenCV " << CV_VERSION << endl;

    Mat img;                     // 이미지를 저장할 Mat 객체 생성

    // 이미지 읽기 (컬러 모드)
    img = imread("lenna.bmp", IMREAD_COLOR);

    // 이미지 로드 실패 여부 확인
    if (img.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;               // 이미지 읽기 실패 시 프로그램 종료
    }

    // 이미지 출력용 창 생성
    namedWindow("image");

    // 이미지를 창에 출력
    imshow("image", img);

    // 밝기 증가 후 이미지 저장
    // img + 100 → 모든 픽셀 값에 100 더하기 (밝게 만듦)
    imwrite("bright.jpg", img + 100);

    // 키 입력 대기
    waitKey();  // 아무 키나 누를 때까지 프로그램 대기

    return 0;   // 프로그램 정상 종료
}