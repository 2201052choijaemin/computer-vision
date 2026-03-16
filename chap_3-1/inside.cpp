#include <opencv2/opencv.hpp>   // OpenCV 라이브러리 사용
#include <iostream>             // 입출력(cin, cout) 사용

using namespace cv;             // OpenCV 네임스페이스 사용
using namespace std;            // std 네임스페이스 사용

int main()
{
    Rect r;                     // 사각형(Rect) 객체 생성
    Point p;                    // 점(Point) 객체 생성

    // 사각형의 왼쪽 위 좌표 입력
    cout << "사각형의 좌측상단의 좌표를 입력하시오(x,y): ";
    cin >> r.x >> r.y;          // 사용자로부터 x, y 좌표 입력

    // 사각형의 폭(width)과 높이(height) 입력
    cout << "사각형의 폭,높이를 입력하시오(width, height): ";
    cin >> r.width >> r.height; // 사용자로부터 폭과 높이 입력

    // 검사할 점 P 좌표 입력
    cout << "점 P의 좌표를 입력하시오: ";
    cin >> p.x >> p.y;          // 사용자로부터 점 좌표 입력

    // 점이 사각형 안에 있는지 검사
    if (p.inside(r))             // inside() 함수: 점이 사각형 내부인지 판단
        cout << "점 P는 사각형 안에 있다." << endl;
    else
        cout << "점 P는 사각형 밖에 있다." << endl;

    return 0;                    // 프로그램 정상 종료
}