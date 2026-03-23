#include <opencv2/opencv.hpp>  // OpenCV 라이브러리 포함
#include <iostream>            // 입출력 스트림 사용
using namespace cv;            // cv 네임스페이스 사용
using namespace std;           // std 네임스페이스 사용

int main()
{
    Mat img(400, 400, CV_8UC3); // 400x400 크기의 3채널(BGR) 이미지 생성 (초기값 미정)

    Scalar colors[3] = {
        Scalar(255, 0, 0),  // 파란색 (BGR)
        Scalar(0, 255, 0),  // 초록색
        Scalar(0, 0, 255)   // 빨간색
    };

    int i = 0;   // 색상 변경을 위한 인덱스 변수
    int key;     // 키 입력 값을 저장할 변수

    while (true) // 무한 반복
    {
        img = colors[i % 3];  // i를 3으로 나눈 나머지로 색상을 순환 적용 (파→초→빨 반복)
        i++;                  // 다음 색상을 위해 증가

        imshow("img", img);   // 현재 이미지를 창에 출력

        key = waitKey(1000);  // 1000ms(1초) 동안 키 입력 대기
        if (key == 'q') break; // 'q' 키를 누르면 반복 종료
    }

    return 0; // 프로그램 정상 종료
}