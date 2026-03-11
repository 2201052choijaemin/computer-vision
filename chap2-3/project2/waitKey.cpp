#include <opencv2/opencv.hpp>  // OpenCV 라이브러리 사용
#include <iostream>             // 콘솔 입출력 사용
using namespace cv;             // OpenCV 함수, 클래스 간단히 사용
using namespace std;            // 표준 C++ 함수, 객체 사용

int main()
{
    int count = 0;              // 초 단위 시간 카운트 변수
    Mat img[3];                 // 3개의 이미지를 저장할 Mat 배열
    string name[3] = { "lenna.bmp", "lenna.bmp2", "lenna.bmp3" }; // 이미지 파일 이름 배열

    // 3개의 이미지를 배열에 읽어오기
    for (int i = 0; i < 3; i++) {
        img[i] = imread(name[i]);   // 이미지 파일 읽기
        if (img[i].empty()) {       // 이미지 로드 실패 여부 확인
            cerr << "Image load failed!" << endl;  // 실패 시 오류 메시지
            return -1;              // 프로그램 종료
        }
    }

    // 무한 반복문: 이미지 3개를 1초 간격으로 번갈아 출력
    while (true)
    {
        imshow("image", img[count % 3]);  // count % 3 → 0,1,2 반복하여 이미지 출력
        cout << count + 1 << "초, 종료하려면 q를 누르세요" << endl; // 콘솔에 시간 출력

        // 1000ms(1초) 대기 후 키 입력 확인
        if (waitKey(1000) == 'q') break;  // 'q' 입력 시 종료
        count++;                          // 1초마다 카운트 증가
    }

    return 0;  // 프로그램 정상 종료
}