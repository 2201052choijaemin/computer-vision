#include <opencv2/opencv.hpp>  // OpenCV 라이브러리 포함
#include <iostream>            // 입출력을 위한 iostream 포함
using namespace cv;            // cv 네임스페이스 사용
using namespace std;           // std 네임스페이스 사용

int main()
{
    Mat img1(400, 300, CV_8UC3, Scalar(255, 0, 0)); // 400x300 크기, 8비트 3채널(BGR) 이미지 생성 (파란색)
    Mat img2(400, 300, CV_8UC3, Scalar(0, 255, 0)); // 초록색 이미지 생성
    Mat img3(400, 300, CV_8UC3, Scalar(0, 0, 255)); // 빨간색 이미지 생성

    imshow("img1", img1); // "img1" 이름의 창에 img1 출력
    imshow("img2", img2); // "img2" 창에 img2 출력
    imshow("img3", img3); // "img3" 창에 img3 출력

    waitKey(); // 키 입력이 있을 때까지 창 유지

    return 0; // 프로그램 정상 종료
}