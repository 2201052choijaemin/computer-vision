#include <opencv2/opencv.hpp>  // OpenCV 라이브러리 포함
#include <iostream>            // 표준 입출력 라이브러리 포함
using namespace cv;            // cv 네임스페이스 사용
using namespace std;           // std 네임스페이스 사용
int main()
{
    Mat img1 = (Mat_<int>(3, 5) << 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11, 12, 13, 14, 15); // 3x5 크기의 정수형 행렬 생성 및 값 초기화

    Mat img2 = img1(Rect(2, 1, 3, 2)).clone(); // (x=2, y=1) 위치에서 가로 3, 세로 2 크기의 ROI 추출 후 복사

    cout << "img1" << endl << img1 << endl; // 원본 행렬 출력
    cout << "img2" << endl << img2 << endl; // 잘라낸 행렬 출력
    return 0; // 프로그램 정상 종료
}






