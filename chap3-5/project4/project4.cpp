#include <iostream>              // 표준 입출력 사용
#include <opencv2/opencv.hpp>   // OpenCV 라이브러리 포함
using namespace cv;             // cv 네임스페이스 생략
using namespace std;            // std 네임스페이스 생략
int main()
{
    Mat img(400, 400, CV_8UC1, Scalar(255)); // 400x400 크기의 그레이스케일 이미지 생성 (흰색으로 초기화)

    for (int x = 0; x < img.cols; x++) {     // x좌표를 0부터 끝까지 반복
        int y = ((1.0 / 400) * x * x);       // y = (1/400)x² 형태의 포물선 계산
        if (y >= 0 && y < img.rows) {        // y가 이미지 범위 안에 있을 때만
            img.at<uchar>(y, x) = 0;         // 해당 좌표를 검은색(0)으로 설정
        }
    }
    imshow("img", img);  // 결과 이미지 출력 (포물선이 그려진 이미지)
    waitKey(0);          // 키 입력 대기
    return 0;            // 정상 종료
}
