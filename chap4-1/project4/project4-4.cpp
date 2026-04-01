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

    Mat frame, result;           // frame: 원본, result: 처리된 이미지 저장

    while (true) {
        cap >> frame;            // 카메라에서 한 프레임 읽기
        if (frame.empty())       // 프레임 비어있으면 루프 종료
            break;

        result = frame.clone();  // 원본 보호를 위해 프레임 복사

        int cx = frame.cols / 2; // 이미지 중심 X 좌표 계산
        int cy = frame.rows / 2; // 이미지 중심 Y 좌표 계산

        // 세로 중앙선 빨간색으로 그리기 (BGR: (0,0,255))
        line(result, Point(cx, 0), Point(cx, frame.rows), Scalar(0, 0, 255), 2);
        // 가로 중앙선 빨간색으로 그리기
        line(result, Point(0, cy), Point(frame.cols, cy), Scalar(0, 0, 255), 2);

        imshow("frame", frame);   // 원본 영상 출력
        imshow("cross", result);  // 빨간 십자선이 그려진 영상 출력

        if (waitKey(30) == 'q')    // 30ms 대기, q 누르면 종료
            break;
    }

    return 0;
}