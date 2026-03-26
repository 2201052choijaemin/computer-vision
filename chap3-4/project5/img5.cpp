#include <opencv2/opencv.hpp>   // OpenCV 라이브러리 포함
#include <iostream>             // 표준 입출력 라이브러리 포함
using namespace cv;             // cv 네임스페이스 사용
using namespace std;            // std 네임스페이스 사용
int main()
{
    Mat img(200, 600, CV_8UC3, Scalar(255, 255, 255)); // 200x600 크기의 컬러 이미지 생성 (흰색 배경)
    int pos = 0; // 사각형 위치를 제어하는 변수 (0,1,2 순환)
    while (true) // 무한 반복
    {
        img.setTo(Scalar(255, 255, 255)); // 매 반복마다 이미지를 흰색으로 초기화
        int x = pos * 200; // 사각형의 x 좌표 계산 (0, 200, 400 위치로 이동)
        rectangle(img, Rect(x, 0, 200, 200), Scalar(0, 0, 255), FILLED);
        // (x,0) 위치에 200x200 크기의 빨간색(BGR: 0,0,255) 사각형을 채워서 그림
        imshow("img", img); // 이미지 출력
        int key = waitKey(1000); // 1초 대기 후 키 입력 받기
        if (key == 'q') break; // 'q' 키를 누르면 반복 종료
        pos = (pos + 1) % 3; // pos 값을 0→1→2→0 순으로 반복 (3칸 순환 이동)
    }
    return 0; // 프로그램 정상 종료
}