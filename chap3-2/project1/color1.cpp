#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
    Vec3b color;  
    int b, g, r;
    cout << "Blue값(0~255)을 입력하시오 : ";
    cin >> b;
    cout << "Green값(0~255)을 입력하시오 : ";
    cin >> g;
    cout << "Red값(0~255)을 입력하시오 : ";
    cin >> r;
    color[0] = b;
    color[1] = g;
    color[2] = r;
    cout << "입력한 컬러값은" << color << "입니다" << endl;
    return 0;
}
