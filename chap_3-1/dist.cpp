#include <opencv2/opencv.hpp>   // OpenCV 라이브러리 사용
#include <iostream>             // 입출력(cin, cout) 사용
#include <cmath>                // sqrt() 같은 수학 함수 사용

using namespace cv;             // cv 네임스페이스 사용
using namespace std;            // std 네임스페이스 사용

int main()
{
    Point pt1(10, 10);          // 첫 번째 점 생성 (x=10, y=10)
    Point pt2(20, 20);          // 두 번째 점 생성 (x=20, y=20)

    cout << "첫 번째 점의 x, y좌표를 입력:" << pt1.x << " " << pt1.y << endl; // pt1 좌표 출력
    cout << "두 번째 점의 x, y좌표를 입력:" << pt2.x << " " << pt2.y << endl; // pt2 좌표 출력

    cout << "pt1:" << pt1 << endl; // Point 객체 자체를 출력 (형식: [x, y])
    cout << "pt2:" << pt2 << endl; // pt2 출력

    double dist;                 // 두 점 사이의 거리 저장할 변수

    // 두 점 사이의 거리 계산 (피타고라스 정리)
    dist = sqrt((pt1.x - pt2.x) * (pt1.x - pt2.x) + (pt1.y - pt2.y) * (pt1.y - pt2.y));

    cout << dist << endl;        // 계산된 거리 출력

    // OpenCV에서 제공하는 norm() 함수로 두 점 사이 거리 계산
    dist = norm(pt1 - pt2);

    cout << dist << endl;        // norm()으로 계산된 거리 출력

    return 0;                    // 프로그램 정상 종료
}