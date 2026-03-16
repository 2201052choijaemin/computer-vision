#include <opencv2/opencv.hpp>   // OpenCV 라이브러리 사용
#include <iostream>             // 입출력(cin, cout) 사용

using namespace cv;             // OpenCV 네임스페이스 사용
using namespace std;            // std 네임스페이스 사용

int main()
{
    Size s1(10, 10);            // 첫 번째 Size 객체 생성 (폭=10, 높이=10)
    Size s2(20, 20);            // 두 번째 Size 객체 생성 (폭=20, 높이=20)

    // 사각형의 폭과 높이 출력
    cout << "첫번째 사각형의 폭,높이 입력:" << s1.width << " " << s1.height << endl;
    cout << "첫번째 사각형의 폭,높이 입력:" << s2.width << " " << s2.height << endl;

    // Size 객체 자체 출력
    cout << "s1:" << s1 << endl; // s1 출력 (형식: [width x height])
    cout << "s2:" << s2 << endl; // s2 출력

    // 면적 계산
    int area1 = s1.area();      // s1 면적 = 폭 * 높이
    int area2 = s2.area();      // s2 면적 = 폭 * 높이

    // 면적 출력
    cout << "s1 면적:" << s1.area() << endl;
    cout << "s2 면적:" << s2.area() << endl;

    return 0;                    // 프로그램 정상 종료
}