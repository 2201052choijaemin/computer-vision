#include <opencv2/opencv.hpp>   // OpenCV 라이브러리 사용
#include <iostream>             // 입출력(cin, cout) 사용

using namespace cv;             // OpenCV 네임스페이스 사용
using namespace std;            // std 네임스페이스 사용

int main()
{
    String str;                 // 파일 이름을 저장할 문자열 변수

    // 0부터 15까지 반복
    for (int i = 0; i < 16; i++)
    {
        // i가 홀수인 경우만 처리
        if (i % 2 == 1) {       // % 연산자 → 나머지 계산, 홀수 판별
            str = format("파일%02d.bmp", i);  // 문자열 포맷: 2자리 숫자, 앞에 0 붙임
            cout << str << endl;              // 생성된 파일 이름 출력
        }
    }

    return 0;                    // 프로그램 정상 종료
}