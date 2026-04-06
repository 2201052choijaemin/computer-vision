#include <opencv2/opencv.hpp>   // OpenCV 라이브러리 포함 (영상 처리 기능)
#include <iostream>             // 표준 입출력 사용

using namespace cv;             // OpenCV 네임스페이스
using namespace std;            // 표준 네임스페이스

int main() {
    VideoCapture cap("stopwatch.avi");   // 영상 파일 열기

    if (!cap.isOpened()) {               // 영상 열기 실패 확인
        cerr << "Camera open failed!" << endl;  // 에러 메시지 출력
        return -1;                       // 프로그램 종료
    }

    int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));   // 영상의 너비 가져오기
    int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));  // 영상의 높이 가져오기

    int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');  // 코덱 설정 (DIVX)

    VideoWriter outputVideo("output.avi", fourcc, 30, Size(w, h));  
    // 결과 영상을 저장할 객체 생성 (파일명, 코덱, FPS, 크기)

    if (!cap.isOpened()) {               // (※ 원래는 outputVideo.isOpened() 확인해야 함)
        cerr << "File open failed!" << endl;  // 파일 생성 실패 메시지
        return -1;                       // 프로그램 종료
    }

    Mat frame, result;                   // frame: 원본, result: 처리 결과

    while (true) {                       // 프레임 반복 처리
        cap >> frame;                    // 한 프레임 읽기

        if (frame.empty())               // 더 이상 읽을 프레임이 없으면
            break;                       // 반복 종료

        result = frame.clone();          // 원본 복사 (수정용)

        int cx = frame.cols / 2;         // 영상 가로 중앙 좌표
        int cy = frame.rows / 2;         // 영상 세로 중앙 좌표

        line(result, Point(cx, 0), Point(cx, frame.rows), Scalar(0, 0, 255), 2);
        // 세로 중앙선 그리기 (빨간색, 두께 2)

        line(result, Point(0, cy), Point(frame.cols, cy), Scalar(0, 0, 255), 2);
        // 가로 중앙선 그리기 (빨간색, 두께 2)

        imshow("fram", frame);           // 원본 영상 출력
        imshow("cross", result);         // 십자선이 그려진 영상 출력

        outputVideo << result;           // 결과 프레임을 파일로 저장

        char key = waitKey(30);          // 30ms 대기하며 키 입력 확인
        if (key == 'q' || key == 'Q') break;  // q 입력 시 종료
    }

    return 0;                            // 프로그램 정상 종료
}
