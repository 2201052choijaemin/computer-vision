#include <opencv2/opencv.hpp>   // OpenCV 라이브러리 포함 (영상 처리)
#include <iostream>             // 표준 입출력 사용

using namespace cv;             // OpenCV 네임스페이스 사용
using namespace std;            // 표준 네임스페이스 사용

int main() {
    VideoCapture cap(0);        // 기본 카메라(웹캠) 열기 (0번 장치)

    if (!cap.isOpened()) {      // 카메라가 정상적으로 열렸는지 확인
        cerr << "Camera open failed!" << endl;  // 실패 시 에러 출력
        return -1;              // 프로그램 종료
    }

    int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));   // 카메라 영상의 너비
    int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));  // 카메라 영상의 높이

    int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');  // 영상 코덱 설정 (DIVX)

    VideoWriter outputVideo("output.avi", fourcc, 30, Size(w, h));
    // 저장할 영상 파일 생성 (파일명, 코덱, FPS, 크기)

    if (!cap.isOpened()) {      // (※ 원래는 outputVideo.isOpened() 확인해야 함)
        cerr << "File open failed!" << endl;  // 파일 생성 실패 메시지
        return -1;              // 프로그램 종료
    }

    Mat frame;                  // 프레임을 저장할 Mat 객체

    while (true) {              // 무한 루프 (실시간 영상 처리)
        cap >> frame;           // 카메라로부터 프레임 읽기

        if (frame.empty()) break;  // 프레임이 비어있으면 종료

        imshow("fram", frame);  // 현재 프레임 화면에 출력

        outputVideo << frame;   // 현재 프레임을 영상 파일에 저장

        char key = waitKey(30); // 30ms 동안 키 입력 대기
        if (key == 'q' || key == 'Q') break;  // q 또는 Q 입력 시 종료
    }

    return 0;                   // 프로그램 정상 종료
}
