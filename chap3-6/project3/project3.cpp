#include <opencv2/opencv.hpp>  // OpenCV 라이브러리 포함
#include <iostream>            // 입출력 스트림 사용
using namespace cv;
using namespace std;

int main()
{
    Mat img = imread("lenna.bmp");   // "lenna.bmp" 이미지 파일 읽기

    if (img.empty()) {               // 이미지 로드 실패 시 처리
        cout << "이미지 로드 실패!" << endl;
        return -1;                   // 프로그램 종료
    }

    int value;
    cout << "밝기 변화량을 입력:";   // 사용자로부터 밝기 변화량 입력 받기
    cin >> value;

    imshow("img", img);              // 원본 이미지 창에 출력

    Mat result;
    result = img + Scalar(value, value, value);
    // 각 픽셀의 B, G, R 채널에 value 만큼 더해서 밝기 증가 (Scalar는 B,G,R 채널에 같은 값 적용)

    imshow("Result", result);        // 밝기 변화 적용된 결과 이미지 출력

    waitKey();                      // 키 입력 대기 (아무 키나 누르면 종료)

    return 0;
}