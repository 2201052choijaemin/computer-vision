#include <opencv2/opencv.hpp>   // OpenCV 라이브러리 사용
#include <iostream>             // 입출력(cin, cout) 사용

using namespace cv;             // OpenCV 네임스페이스 사용
using namespace std;            // std 네임스페이스 사용

int main()
{
    Rect r1(10, 10, 20, 20);       // 사각형 r1 생성: 왼쪽 위 (10,10), 폭=20, 높이=20
    Point p1(10, 10);              // 점 p1 생성: 좌표 (10,10)

    // r1에 (1,1) 만큼 이동한 새로운 사각형을 만들고,
    // 그 안에 p1이 있는지 contains()로 확인
    if ((r1 + Point(1, 1)).contains(p1))
        cout << "내부에 존재" << endl;  // 조건 만족 → 점이 사각형 안에 있음
    else
        cout << "외부에 존재" << endl;  // 조건 불만족 → 점이 사각형 밖

    return 0;                        // 프로그램 정상 종료
}