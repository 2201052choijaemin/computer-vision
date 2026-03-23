#include <opencv2/opencv.hpp>  // OpenCV 라이브러리 포함
#include <iostream>            // 입출력 스트림 사용
using namespace cv;            // cv 네임스페이스 사용
using namespace std;           // std 네임스페이스 사용

int main()
{
    Mat img(400, 400, CV_8UC1, Scalar(0)); // 400x400 크기, 1채널(그레이스케일) 이미지 생성 (초기값 0 = 검정)

    int gray = 0;  // 현재 밝기 값 (0~255)
    int dir = 1;   // 밝기 변화 방향 (1: 증가, -1: 감소)
    int key;       // 키 입력 저장 변수

    while (true)   // 무한 반복
    {
        img = Scalar(gray);   // 이미지 전체를 현재 gray 값으로 채움 (밝기 설정)

        imshow("img", img);   // 이미지 출력

        key = waitKey(5);     // 5ms 동안 키 입력 대기
        if (key == 'q' || key == 'Q') break; // q 또는 Q 입력 시 종료

        gray += dir;          // 밝기 값을 방향에 따라 증가 또는 감소

        if (gray == 255) dir = -1; // 최대 밝기에 도달하면 감소 방향으로 변경
        else if (gray == 0) dir = 1; // 최소 밝기에 도달하면 증가 방향으로 변경
    }

    return 0; // 프로그램 정상 종료
}