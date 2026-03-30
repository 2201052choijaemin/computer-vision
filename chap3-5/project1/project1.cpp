#include <iostream>              // 표준 입출력 사용
#include <opencv2/opencv.hpp>   // OpenCV 라이브러리 포함
using namespace std;            // std 네임스페이스 생략
using namespace cv;             // cv 네임스페이스 생략

int main() {
    Mat img = imread("lenna.bmp", IMREAD_COLOR);  // 이미지 파일을 컬러로 읽기
    if (img.empty()) {                            // 이미지가 비어있는지 확인
        cout << "이미지를 불러올 수 없습니다." << endl; // 에러 메시지 출력
        return -1;                                // 프로그램 종료
    }

    Point xy[] = { Point(50, 50), Point(100, 100), Point(150, 150) }; // 좌표 3개 설정
    for (int i = 0; i < 3; i++) {             // 3개의 좌표 반복
        int x = xy[i].x;                      // x 좌표 추출
        int y = xy[i].y;                      // y 좌표 추출
        Vec3b pixel = img.at<Vec3b>(y, x);    // (y, x) 위치의 픽셀 값 가져오기 (BGR)
        int B = pixel[0];                     // Blue 값
        int G = pixel[1];                     // Green 값
        int R = pixel[2];                     // Red 값
        cout << "좌표(" << x << "," << y << ")의 화소값(B,R,G) :" 
             << B << "," << G << "," << R << endl; // 픽셀 값 출력
    }
    return 0;                                 // 정상 종료
}
