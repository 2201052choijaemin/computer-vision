#include <opencv2/opencv.hpp>  // OpenCV 라이브러리 포함
#include <iostream>            // 입출력 스트림 사용
using namespace cv;
using namespace std;

int main() {
    VideoCapture cap(0);         // 기본 카메라(번호 0) 연결 시도

    if (!cap.isOpened()) {       // 카메라 연결 실패 시
        cerr << "Camera open failed!" << endl;
        return -1;               // 프로그램 종료
    }

    Mat frame, result;           // 프레임 저장용 Mat 객체 두 개 선언 (원본과 처리 결과)

    while (true) {
        cap >> frame;            // 카메라로부터 한 프레임 읽기

        if (frame.empty())       // 프레임 읽기 실패 (비었으면) 루프 종료
            break;

        result = frame + Scalar(100, 100, 100);
        // 각 픽셀의 B, G, R 채널에 100씩 더해 밝기를 밝게 조절 (밝은 영상 생성)

        imshow("frame", frame);   // 원본 프레임 출력 (창 이름: "frame")
        imshow("result", result); // 밝기 조절된 결과 프레임 출력 (창 이름: "result")

        if (waitKey(30) == 'q')  // 30ms 동안 키 입력 대기, q가 눌리면 종료
            break;
    }

    return 0;
}