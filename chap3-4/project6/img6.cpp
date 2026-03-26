#include <opencv2/opencv.hpp>   // OpenCV 라이브러리 포함
#include <iostream>             // 표준 입출력 라이브러리 포함
using namespace cv;             // cv 네임스페이스 사용
using namespace std;            // std 네임스페이스 사용
int main()
{
    Mat img = imread("lenna.bmp"); // lenna.bmp 이미지를 읽어서 img에 저장
    if (img.empty()) { // 이미지 로드 실패 여부 확인
        cerr << "Image load failed!" << endl; // 에러 메시지 출력
        return -1; // 프로그램 종료
    }
    int x, y, w, h, value; // ROI 좌표 및 밝기 변화량 변수 선언
    cout << "관심영영의 좌측상단 좌표(x,y):"; // 사용자에게 ROI 입력 안내
    cin >> x >> y; //RoI의 시간 좌표(x,y) 입력
    cout << "관심영역의 폭,높이(width,height):"; // 사용자에게 ROI 입력 안내
    cin >> w >> h; // ROI의 크기(w,h) 입력
    cout << "밝기 변화량 입력: "; // 밝기 변화량 입력 안내
    cin >> value; // 밝기 증가/감소 값 입력
    Rect roi(x, y, w, h); // ROI(관심 영역) 객체 생성
    img(roi) += Scalar(value, value, value);
    // ROI 영역의 B, G, R 채널 각각에 value를 더해서 밝기 증가
    // (음수를 입력하면 밝기 감소도 가능)
    imshow("Result", img); // 결과 이미지를 창에 출력
    waitKey(); // 키 입력 대기
    return 0; // 프로그램 정상 종료
}