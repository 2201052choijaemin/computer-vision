#include <opencv2/opencv.hpp>  // OpenCV 라이브러리 포함
#include <iostream>            // 입출력 스트림 사용
using namespace cv;
using namespace std;

int main() {
    VideoCapture cap(0);         // 기본 카메라(0번 장치) 연결 시도
    if (!cap.isOpened()) {       // 카메라 연결 실패 시
        cerr << "Camera open failed!" << endl;
        return -1;               // 프로그램 종료
    }

    Mat frame;                    // 카메라에서 읽은 프레임을 저장할 객체
    int count = 0;                // 저장할 이미지 파일 번호 초기화

    while (true) {
        cap >> frame;             // 카메라로부터 한 프레임 읽기
        if (frame.empty())        // 프레임이 비어있으면 루프 종료
            break;

        imshow("frame", frame);   // 현재 프레임 화면에 출력

        char key = waitKey(30);   // 30ms 대기 후 키 입력 감지

        if (key == 'q' || key == 'Q')  // q 또는 Q 누르면 루프 종료
            break;

        if (key == 's') {         // s 누르면 현재 프레임 저장
            string filename = format("frame%02d.jpg", count++);
            // 파일명: frame00.jpg, frame01.jpg, ... (2자리 숫자)
            imwrite(filename, frame); // 이미지 파일 저장
        }
    }

    return 0;
}