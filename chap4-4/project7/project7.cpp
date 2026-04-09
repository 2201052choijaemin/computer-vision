#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
Mat img;
int lastClicked = -1;
void on_mouse(int event, int x, int y, int flags, void* userdata);
int main() {
    img = Mat(300, 500, CV_8UC3, Scalar(255, 255, 255));

    Rect redRect(0, 0, 200, 100);
    Rect greenRect(0, 100, 200, 100);
    Rect blueRect(0, 200, 200, 100);

    rectangle(img, redRect, Scalar(255, 255, 255), FILLED);
    rectangle(img, greenRect, Scalar(255, 255, 255), FILLED);
    rectangle(img, blueRect, Scalar(255, 255, 255), FILLED);

    rectangle(img, redRect, Scalar(0, 0, 0), 2);
    rectangle(img, greenRect, Scalar(0, 0, 0), 2);
    rectangle(img, blueRect, Scalar(0, 0, 0), 2);

    putText(img, "Red", Point(70, 58), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(0, 0, 0), 2);
    putText(img, "Green", Point(55, 158), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(0, 0, 0), 2);
    putText(img, "Blue", Point(65, 258), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(0, 0, 0), 2);

    namedWindow("Menu");
    setMouseCallback("Menu", on_mouse);
    imshow("Menu", img);
    int key;
    while (true) {
        key = waitKey(10);
        if (key == 'q') break;
    }
    return 0;
}
void on_mouse(int event, int x, int y, int flags, void* userdata) {
    switch (event) {
    case EVENT_LBUTTONDOWN:
        if (x >= 0 && x < 200) {
            if (y >= 0 && y < 100) lastClicked = 0;
            else if (y >= 100 && y < 200) lastClicked = 1;
            else if (y >= 200 && y < 300) lastClicked = 2;
        }
        img = Mat(300, 500, CV_8UC3, Scalar(255, 255, 255));
        Rect redRect(0, 0, 200, 100);
        Rect greenRect(0, 100, 200, 100);
        Rect blueRect(0, 200, 200, 100);
        rectangle(img, redRect, Scalar(255, 255, 255), FILLED);
        rectangle(img, greenRect, Scalar(255, 255, 255), FILLED);
        rectangle(img, blueRect, Scalar(255, 255, 255), FILLED);
        switch (lastClicked) {
        case 0: rectangle(img, redRect, Scalar(0, 0, 0), FILLED); break;
        case 1: rectangle(img, greenRect, Scalar(0, 0, 0), FILLED); break;
        case 2: rectangle(img, blueRect, Scalar(0, 0, 0), FILLED); break;
        }
        rectangle(img, redRect, Scalar(0, 0, 0), 2);
        rectangle(img, greenRect, Scalar(0, 0, 0), 2);
        rectangle(img, blueRect, Scalar(0, 0, 0), 2);
        Scalar redTextColor = (lastClicked == 0) ? Scalar(255, 255, 255) : Scalar(0, 0, 0);
        Scalar greenTextColor = (lastClicked == 1) ? Scalar(255, 255, 255) : Scalar(0, 0, 0);
        Scalar blueTextColor = (lastClicked == 2) ? Scalar(255, 255, 255) : Scalar(0, 0, 0);
        putText(img, "Red", Point(70, 58), FONT_HERSHEY_SIMPLEX, 1.0, redTextColor, 2);
        putText(img, "Green", Point(55, 158), FONT_HERSHEY_SIMPLEX, 1.0, greenTextColor, 2);
        putText(img, "Blue", Point(65, 258), FONT_HERSHEY_SIMPLEX, 1.0, blueTextColor, 2);
        switch (lastClicked) {
        case 0: putText(img, "Red pressed.", Point(230, 158), FONT_HERSHEY_SIMPLEX, 0.9, Scalar(0, 0, 0), 2); break;
        case 1: putText(img, "Green pressed.", Point(230, 158), FONT_HERSHEY_SIMPLEX, 0.9, Scalar(0, 0, 0), 2); break;
        case 2: putText(img, "Blue pressed.", Point(230, 158), FONT_HERSHEY_SIMPLEX, 0.9, Scalar(0, 0, 0), 2); break;
        }
        imshow("Menu", img);
        break;
    }
}
