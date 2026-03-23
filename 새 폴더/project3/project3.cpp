#include <opencv2/opencv.hpp>  // OpenCV 라이브러리 포함
#include <iostream>            // 입출력을 위한 iostream 포함
using namespace cv;            // cv 네임스페이스 사용
using namespace std;           // std 네임스페이스 사용

int main()
{
    Mat img(300, 400, CV_8UC3, Scalar(0, 0, 0)); // 300x400 크기, 3채널(BGR) 검은색 이미지 생성

    int B, G, R; // Blue, Green, Red 값을 저장할 변수

    cout << "B 값을 입력하라: "; // 파란색 값 입력 안내
    cin >> B;                   // 사용자로부터 B 값 입력

    cout << "G 값을 입력하라: "; // 초록색 값 입력 안내
    cin >> G;                   // 사용자로부터 G 값 입력

    cout << "R 값을 입력하라: "; // 빨간색 값 입력 안내
    cin >> R;                   // 사용자로부터 R 값 입력

    img.setTo(Scalar(B, G, R)); // 입력받은 BGR 값으로 이미지 전체 색상 설정

    imshow("Color Window", img); // "Color Window" 창에 이미지 출력

    waitKey(0); // 키 입력이 있을 때까지 창 유지

    return 0; // 프로그램 정상 종료
}