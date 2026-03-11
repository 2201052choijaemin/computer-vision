#include <opencv2/opencv.hpp>   // OpenCV 라이브러리 사용 (이미지 처리 함수)
#include <iostream>             // 콘솔 입출력 사용
using namespace cv;             // OpenCV 네임스페이스
using namespace std;            // 표준 C++ 네임스페이스

int main()
{
    int count = 0;              // 시간을 카운트하기 위한 변수 (초 단위 증가)
    Mat img[10];                // 10개의 이미지를 저장할 Mat 객체 배열

    // 이미지 파일 이름을 저장하는 문자열 배열
    string name[10] = { "c0.bmp", "c1.bmp", "c2.bmp", "c3.bmp", "c4.bmp",
                        "c5.bmp", "c6.bmp", "c7.bmp", "c8.bmp", "c9.bmp" };

    // for문을 이용하여 10개의 이미지를 배열에 불러옴
    for (int i = 0; i < 10; i++) {
        img[i] = imread(name[i]);       // imread() 함수를 이용해 이미지 파일을 읽어옴

        // 이미지 로드 실패 여부 확인
        if (img[i].empty()) {           // 이미지가 비어있다면 로드 실패
            cerr << "Image load failed!" << endl;  // 오류 메시지 출력
            return -1;                  // 프로그램 종료
        }
    }

    // 무한 반복문을 통해 이미지를 계속 출력
    while (true)
    {
        // count 값을 10으로 나눈 나머지를 이용하여 0~9 이미지를 반복 출력
        imshow("image", img[count % 10]);

        // 현재 시간을 콘솔에 출력
        cout << count + 1 << "초, 종료하려면 q를 누르세요" << endl;

        // waitKey(1000)은 1000ms(1초) 동안 대기하며 키 입력을 받음
        // 만약 'q' 키가 눌리면 반복문을 종료
        if (waitKey(1000) == 'q') break;

        count++;   // 1초마다 카운트 값 증가
    }

    return 0;      // 프로그램 정상 종료
}