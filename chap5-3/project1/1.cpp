#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
    Mat img = imread("lenna.bmp", IMREAD_GRAYSCALE);

    if (img.empty())
    {
        cout << "영상 파일을 열 수 없습니다." << endl;
        return -1;
    }
    imshow("lenna.bmp", img);
    int totalPixels = img.rows * img.cols;
    double minVal, maxVal;
    minMaxLoc(img, &minVal, &maxVal);
    int hist[256] = { 0 };
    for (int y = 0; y < img.rows; y++)
    {
        for (int x = 0; x < img.cols; x++)
        {
            int value = img.at<uchar>(y, x);
            hist[value]++;
        }
    }
    int maxFreq = 0;
    int maxPixel = 0;
    for (int i = 0; i < 256; i++)
    {
        if (hist[i] > maxFreq)
        {
            maxFreq = hist[i];
            maxPixel = i;
        }
    }
    int freq80 = hist[80];
    cout << "영상의 전체 픽셀수: " << totalPixels << endl;
    cout << "영상에서 픽셀값의 최소값: " << minVal << endl;
    cout << "영상에서 픽셀값의 최대값: " << maxVal << endl;
    cout << "빈도수가 가장 많은 픽셀값과 빈도수: "
        << maxPixel << "." << maxFreq << endl;
    cout << "픽셀값 80의 빈도수: " << freq80 << endl;
    waitKey(0);
    return 0;
}
