#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
Mat calcGrayHist(const Mat& img);
Mat getGrayHistImage(const Mat& hist);
int main()
{
    Mat src = imread("crayfish.jpg", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }
    double gmin, gmax;
    minMaxLoc(src, &gmin, &gmax);

    cout << "gmin : " << gmin << endl;
    cout << "gmax : " << gmax << endl;
    Mat dst(src.rows, src.cols, CV_8UC1);
    for (int y = 0; y < src.rows; y++) {
        for (int x = 0; x < src.cols; x++) {

            uchar pixel = src.at<uchar>(y, x);

            double value =
                (pixel - gmin) * 255.0 / (gmax - gmin);

            dst.at<uchar>(y, x) =
                saturate_cast<uchar>(value);
        }
    }
    imshow("src", src);
    imshow("dst", dst);
    imshow("srcHist", getGrayHistImage(calcGrayHist(src)));
    imshow("dstHist", getGrayHistImage(calcGrayHist(dst)));
    waitKey();
    destroyAllWindows();
    return 0;
}
Mat calcGrayHist(const Mat& img)
{
    CV_Assert(img.type() == CV_8UC1);
    Mat hist;
    int channels[] = { 0 };
    int dims = 1;
    const int histSize[] = { 256 };
    float graylevel[] = { 0, 256 };
    const float* ranges[] = { graylevel };
    calcHist(&img,1,channels,noArray(),hist,dims,histSize,ranges);
    return hist;
}
Mat getGrayHistImage(const Mat& hist)
{
    CV_Assert(hist.type() == CV_32FC1);
    CV_Assert(hist.size() == Size(1, 256));

    double histMax;
    minMaxLoc(hist, 0, &histMax);

    Mat imgHist(100, 256, CV_8UC1, Scalar(255));

    for (int i = 0; i < 256; i++) {

        line(imgHist,
            Point(i, 100),
            Point(i,100 - cvRound(hist.at<float>(i, 0) * 100 / histMax)), Scalar(0));
    }
    return imgHist;
}
