#include <iostream>              // 표준 입출력 사용
#include <opencv2/opencv.hpp>   // OpenCV 라이브러리 포함
using namespace cv;             // cv 네임스페이스 생략
using namespace std;            // std 네임스페이스 생략

int main()
{
    Mat img = imread("lenna.bmp", IMREAD_COLOR); // 컬러 이미지로 읽기 (BGR 3채널)
    if (img.empty()) return -1;                  // 이미지 로드 실패 시 종료

    int line_x[3] = { img.cols / 4, img.cols / 2, (img.cols * 3) / 4 }; // 세로선 위치(x좌표 3개)
    int line_y[3] = { img.rows / 4, img.rows / 2, (img.rows * 3) / 4 }; // 가로선 위치(y좌표 3개)

    for (int y = 0; y < img.rows; y++) { // 모든 y(행)에 대해 반복
        for (int i = 0; i < 3; i++) {    // 세로선 3개 반복
            int x = line_x[i];           // 현재 세로선의 x좌표
            img.at<Vec3b>(y, x)[0] = 255; // Blue 채널을 255로 설정
            img.at<Vec3b>(y, x)[1] = 255; // Green 채널을 255로 설정
            img.at<Vec3b>(y, x)[2] = 255; // Red 채널을 255로 설정 → 결과적으로 흰색 선
        }
    }
    for (int x = 0; x < img.cols; x++) { // 모든 x(열)에 대해 반복
        for (int i = 0; i < 3; i++) {    // 가로선 3개 반복
            int y = line_y[i];           // 현재 가로선의 y좌표
            img.at<Vec3b>(y, x)[0] = 255; // Blue 채널을 255로 설정
            img.at<Vec3b>(y, x)[1] = 255; // Green 채널을 255로 설정
            img.at<Vec3b>(y, x)[2] = 255; // Red 채널을 255로 설정 → 결과적으로 흰색 선
        }
    }

    imshow("Grid 4x4", img);  // 결과 이미지 출력 (4x4 격자 형태)
    waitKey(0);               // 키 입력 대기
    return 0;                 // 정상 종료
}
