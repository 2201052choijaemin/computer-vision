#include <opencv2/opencv.hpp> // OpenCV 라이브러리 포함
#include <iostream>            // 표준 입출력 라이브러리 포함
using namespace cv;           // cv 네임스페이스 사용
using namespace std;          // std 네임스페이스 사용

int main()
{
    Mat img = imread("lenna.bmp"); // lenna.bmp 이미지를 읽어 img에 저장
    if (img.empty()) {             // 이미지 로드 실패 여부 확인
        cerr << "Image load failed!" << endl; // 실패 시 에러 메시지 출력
        return -1;                 // 프로그램 종료
    }
    int x, y, w, h, value;        // ROI 좌표(x,y), 크기(w,h), 밝기 변화량(value) 변수 선언
    cout << "관심영역의 좌측상단 좌표(x,y):"; // 사용자에게 ROI 좌상단 좌표 입력 안내
    cin >> x >> y;                 // x, y 입력 받기
    cout << "관심영역의 폭,높이(width,height):"; // 사용자에게 ROI 폭과 높이 입력 안내
    cin >> w >> h;                 // w, h 입력 받기
    cout << "밝기 변화량 입력: "; // 사용자에게 밝기 증가/감소 값 입력 안내
    cin >> value;                  // value 입력 받기
    Rect roi(x, y, w, h);          // 입력받은 좌표와 크기로 ROI(Rect 객체) 생성
    Mat img2 = img(roi);           // ROI 영역만 img2에 복사 (원본 img는 그대로 유지)
    Mat img3 = img2 + Scalar(value, value, value); // ROI의 BGR 채널 각각에 value를 더해서 밝기 조절
    img3.copyTo(img(roi));         // 밝기 조절된 ROI를 원본 이미지의 동일 위치에 복사
    imshow("Result", img);         // 결과 이미지를 창에 출력
    waitKey();                      // 키 입력 대기 (창이 바로 닫히지 않도록)
    return 0;                       // 프로그램 정상 종료
}
