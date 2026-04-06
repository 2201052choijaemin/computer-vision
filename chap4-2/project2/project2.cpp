#include <opencv2/opencv.hpp>  // OpenCV 라이브러리 포함 (영상 처리 기능 제공)
#include <iostream>            // 입출력 스트림 사용을 위한 헤더

using namespace cv;            // cv 네임스페이스 사용 (OpenCV 함수 간편 사용)
using namespace std;           // std 네임스페이스 사용 (cout 등 간편 사용)

int main()
{
    VideoCapture cap("stopwatch.avi");  // "stopwatch.avi" 영상 파일을 열기 위한 객체 생성

    if (!cap.isOpened()) {              // 영상 파일이 제대로 열렸는지 확인
        cout << "카메라 열기 실패!" << endl;  // 실패 시 메시지 출력
        return -1;                      // 프로그램 종료 (에러 코드 반환)
    }

    Mat frame, result;                  // frame: 원본 영상, result: 밝기 증가된 영상 저장용

    while (true) {                      // 무한 루프 (영상 프레임 반복 처리)
        cap >> frame;                   // 한 프레임 읽어오기
        if (frame.empty()) break;       // 프레임이 비어있으면 (영상 끝) 반복 종료

        result = frame + Scalar(100, 100, 100);  // 각 픽셀의 BGR 값에 100씩 더해 밝기 증가

        imshow("Original", frame);      // 원본 영상 화면에 출력
        imshow("Result", result);       // 밝기 증가된 영상 화면에 출력

        char key = waitKey(30);         // 30ms 동안 키 입력 대기
        if (key == 'q' || key == 'Q') break;  // q 또는 Q 입력 시 반복 종료
    }

    return 0;                           // 프로그램 정상 종료
}
