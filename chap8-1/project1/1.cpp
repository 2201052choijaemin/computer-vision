#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main(void) {
    Mat src = imread("tekapo.bmp");
    if (src.empty()) {
        cerr << "Image load error!" << endl;
        return -1;
    }

    Point2f srcPts[3], dstPts[3];

    srcPts[0] = Point2f(0.f, 0.f);
    srcPts[1] = Point2f(src.cols - 1.f, 0.f);
    srcPts[2] = Point2f(src.cols - 1.f, src.rows - 1.f);

    dstPts[0] = Point2f(0.f, 0.f);
    dstPts[1] = Point2f((src.cols - 1.f)/ 2, 0.f);
    dstPts[2] = Point2f((src.cols - 1.f) / 2, (src.rows - 1.f)/2);

    Mat M = getAffineTransform(srcPts, dstPts);
    cout << "Transformation Matrix M: \n" << M << endl;

    Mat dst;
    warpAffine(src, dst, M, Size(src.cols/2, src.rows/2));

    imshow("src", src);
    imshow("dst", dst);

    waitKey(0);
    return 0;
}


#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main(void) {
    Mat src = imread("tekapo.bmp");
    if (src.empty()) {
        cerr << "Image load error!" << endl;
        return -1;
    }

    Point2f srcPts[3], dstPts[3];

    srcPts[0] = Point2f(0.f, 0.f);
    srcPts[1] = Point2f(src.cols - 1.f, 0.f);
    srcPts[2] = Point2f(src.cols - 1.f, src.rows - 1.f);

    dstPts[0] = Point2f(0.f, 0.f);
    dstPts[1] = Point2f((src.cols - 1.f) * 2, 0.f);
    dstPts[2] = Point2f((src.cols - 1.f) * 2, (src.rows - 1.f) * 2);

    Mat M = getAffineTransform(srcPts, dstPts);
    cout << "Transformation Matrix M: \n" << M << endl;

    Mat dst;
    warpAffine(src, dst, M, Size(src.cols * 2, src.rows * 2));

    imshow("src", src);
    imshow("dst", dst);

    waitKey(0);
    return 0;
}

