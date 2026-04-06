#include <opencv2/opencv.hpp>   // OpenCV 라이브러리 포함 (영상 처리)
#include <iostream>             // 표준 입출력 사용

using namespace cv;             // OpenCV 네임스페이스
using namespace std;            // 표준 네임스페이스

int main() {
    VideoCapture cap(0);        // 기본 웹캠 열기

    if (!cap.isOpened()) {      // 카메라 열기 실패 확인
        cerr << "Camera open failed!" << endl;
        return -1;              // 실패 시 종료
    }

    int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));   // 프레임 너비
    int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));  // 프레임 높이

    int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');  // 코덱 설정

    VideoWriter outputVideo;    // 영상 저장 객체 (초기에는 열지 않음)

    bool recoding = false;      // 녹화 상태 여부 (false = 녹화 안함)

    Mat frame;                  // 프레임 저장 변수

    while (true) {              // 무한 루프 (실시간 처리)
        cap >> frame;           // 카메라에서 프레임 읽기

        if (frame.empty()) break;   // 프레임 없으면 종료

        imshow("fram", frame);  // 현재 프레임 출력

        char key = waitKey(30); // 키 입력 대기

        if (key == 's') {       // 's' 키를 누르면 녹화 시작
            if (recoding = true) {  // (※ 비교가 아니라 대입이라 항상 true가 됨 - 논리 오류)
                outputVideo.open("output.avi", fourcc, 30, Size(w, h));
                // 영상 파일 열기 (녹화 시작)

                if (!cap.isOpened()) {  // (※ 원래는 outputVideo.isOpened() 확인해야 함)
                    cerr << "File open failed!" << endl;
                    return -1;
                }
            }
            recoding = true;    // 녹화 상태를 true로 설정
            cout << "실행" << endl;  // 녹화 시작 메시지
        }

        if (key == 'e') {       // 'e' 키를 누르면 녹화 종료
            if (recoding) {     // 녹화 중일 때만
                recoding = false;   // 녹화 상태 해제
                cout << "종료" << endl;  // 종료 메시지
                break;          // 반복문 종료 (프로그램 끝)
            }
        }

        if (recoding) {         // 녹화 중이면
            outputVideo << frame;   // 프레임을 영상 파일로 저장
        }
    }

    return 0;                   // 프로그램 정상 종료
}
