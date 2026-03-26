#include <opencv2/opencv.hpp>   // OpenCV 라이브러리 포함
#include <iostream>             // 표준 입출력 라이브러리 포함
using namespace cv;             // cv 네임스페이스 사용
using namespace std;            // std 네임스페이스 사용

int main()
{
    Mat img1 = imread("dog.bmp", IMREAD_COLOR);   // 이미지 파일을 컬러로 읽어서 img1에 저장
    // 이미지가 정상적으로 로드되지 않았을 경우
    if (img1.empty()) {
        cerr << "Image load failed!" << endl; // 에러 메시지 출력
        return -1; // 프로그램 종료
    }
    Rect face(91, 36, 90, 88); // 관심 영역(ROI) 설정 (x=91, y=36, 너비=90, 높이=88)
    Mat original = img1.clone();     // 원본 이미지를 복사하여 저장 (원본 보존용)
    Mat colored = img1.clone();   // ROI에 색을 입힌 이미지를 만들기 위해 복사
    colored(face) = Scalar(255, 0, 0);   // face 영역을 파란색(BGR: 255,0,0)으로 채움
    Mat imgs[2] = { original, colored }; // 두 이미지를 배열에 저장 (0: 원본, 1: 색칠된 이미지)
    int idx = 0; // 현재 보여줄 이미지 인덱스 (0 또는 1)
    while (true) {
        imshow("img1", imgs[idx]); // 현재 인덱스에 해당하는 이미지를 화면에 출력
        if (waitKey(1000) == 'q') break; // 1초(1000ms) 대기 후 'q' 키가 입력되면 반복 종료
        idx = (idx + 1) % 2;   // 인덱스를 0과 1 사이에서 번갈아 변경
    }
    return 0; // 프로그램 정상 종료
}
