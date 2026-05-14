#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
Mat calcGrayHist(const Mat& img)
{
    CV_Assert(img.type() == CV_8UC1);
    Mat hist;
    int channels[] = { 0 };
    int dims = 1;
    const int histSize[] = { 256 };
    float graylevel[] = { 0, 256 };
    const float* ranges[] = { graylevel };
    calcHist(&img, 1, channels, noArray(), hist,
        dims, histSize, ranges);
    return hist;
}
Mat mycalcGrayHist(const Mat& img)
{
    CV_Assert(img.type() == CV_8UC1);

    Mat hist = Mat::zeros(256, 1, CV_32F);

    for (int y = 0; y < img.rows; y++)
    {
        for (int x = 0; x < img.cols; x++)
        {
            int v = img.at<uchar>(y, x);
            hist.at<float>(v, 0)++;
        }
    }
    return hist;
}
Mat getGrayHistImage(const Mat& hist)
{
    CV_Assert(hist.type() == CV_32FC1);
    CV_Assert(hist.size() == Size(1, 256));
    double histMax = 0;
    minMaxLoc(hist, 0, &histMax);
    Mat imgHist(100, 256, CV_8UC1, Scalar(255));

    for (int i = 0; i < 256; i++)
    {
        line(imgHist,
            Point(i, 100),
            Point(i, 100 - cvRound(hist.at<float>(i, 0) * 100 / histMax)),
            Scalar(0));
    }
    return imgHist;
}
int main()
{
    Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

    if (src.empty())
    {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    imshow("src", src);

    Mat hist = mycalcGrayHist(src);

    Mat hist_img = getGrayHistImage(hist);

    imshow("srcHist", hist_img);

    waitKey(0);
    return 0;
}
