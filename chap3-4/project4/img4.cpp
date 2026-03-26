#include <opencv2/opencv.hpp>   // OpenCV 라이브러리 포함
#include <iostream>             // 표준 입출력 라이브러리 포함
using namespace cv;             // cv 네임스페이스 사용
using namespace std;            // std 네임스페이스 사용
int main()
{
    Mat img1 = imread("dog.bmp", IMREAD_COLOR); // dog.bmp 이미지를 컬러로 읽어서 img1에 저장
    if (img1.empty()) { // 이미지가 정상적으로 로드되지 않았는지 확인
        cerr << "Image load failed!" << endl; // 에러 메시지 출력
        return -1; // 프로그램 종료
    }
    Rect face(91, 36, 90, 88); // ROI(관심 영역) 설정 (x=91, y=36, 너비=90, 높이=88)
    Mat copy; // ROI 영역을 저장할 Mat 객체 선언
    img1(face).copyTo(copy); // face 영역을 copy 변수에 복사 (원본 보존)
    while (true) { // 무한 반복 루프 시작
        img1(face) = Scalar(255, 0, 0); // ROI 영역을 파란색(BGR)으로 채움
        imshow("img1", img1); // 이미지 출력
        if (waitKey(1000) == 'q') break; // 1초 대기 후 'q' 입력 시 반복 종료
        copy.copyTo(img1(face)); // 저장해둔 원본 ROI를 다시 복원
        imshow("img1", img1); // 이미지 출력
        if (waitKey(1000) == 'q') break; // 1초 대기 후 'q' 입력 시 반복 종료
    }
    return 0; // 프로그램 정상 종료
}