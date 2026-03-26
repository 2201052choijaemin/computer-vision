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
    img1(face) = Scalar(255, 0, 0); // 해당 영역을 파란색(BGR: 255,0,0)으로 채움
    imshow("img1", img1); // 결과 이미지를 창에 출력
    waitKey(); // 키 입력이 있을 때까지 대기
    return 0; // 프로그램 정상 종료
}