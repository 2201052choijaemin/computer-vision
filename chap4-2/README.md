#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
    VideoCapture cap("stopwatch.avi");

    if (!cap.isOpened()) {
        cout << "카메라 열기 실패!" << endl;
        return -1;
    }
    Mat frame, result;
    while (true) {
        cap >> frame; 
        if (frame.empty()) break;
        result = frame + Scalar(100, 100, 100);
        imshow("Original", frame);
        imshow("Result", result);
        char key = waitKey(30);
        if (key == 'q' || key == 'Q') break;
    }
    return 0;
}

#include <opencv2/opencv.hpp>  
#include <iostream>            
using namespace cv;
using namespace std;
int main() {
    VideoCapture cap("stopwatch.avi");
    if (!cap.isOpened()) {       
        cerr << "Camera open failed!" << endl;
        return -1;               
    }
    int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
    int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
    int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');
    VideoWriter outputVideo("output.avi", fourcc, 30, Size(w, h));
    if (!cap.isOpened()) {
        cerr << "File open failed!" << endl;
        return -1;
    }
    Mat frame, result;           
    while (true) {
        cap >> frame;            
        if (frame.empty())       
            break;
        result = frame.clone();
        int cx = frame.cols / 2;
        int cy = frame.rows / 2;
        line(result, Point(cx, 0), Point(cx, frame.rows), Scalar(0, 0, 255), 2);
        line(result, Point(0, cy), Point(frame.cols, cy), Scalar(0, 0, 255), 2);
        imshow("fram", frame);  
        imshow("cross", result);  
        outputVideo << result;
        char key = waitKey(30);
        if (key == 'q' || key == 'Q') break;
    }
    return 0;
}

#include <opencv2/opencv.hpp>  
#include <iostream>            
using namespace cv;
using namespace std;
int main() {
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cerr << "Camera open failed!" << endl;
        return -1;
    }
    int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
    int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
    int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');
    VideoWriter outputVideo("output.avi", fourcc, 30, Size(w, h));
    if (!cap.isOpened()) {
        cerr << "File open failed!" << endl;
        return -1;
    }
    Mat frame;
    while (true) {
        cap >> frame;
        if (frame.empty()) break;
        imshow("fram", frame);
        outputVideo << frame;
        char key = waitKey(30);
        if (key == 'q' || key == 'Q') break;
    }
    return 0;
}

#include <opencv2/opencv.hpp>  
#include <iostream>            
using namespace cv;
using namespace std;
int main() {
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cerr << "Camera open failed!" << endl;
        return -1;
    }
    int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
    int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
    int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');
    VideoWriter outputVideo;
    bool recoding = false;
    Mat frame;
    while (true) {
        cap >> frame;
        if (frame.empty()) break;
        imshow("fram", frame);
        char key = waitKey(30);
        if (key == 's') {
            if (recoding = true) {
                outputVideo.open("output.avi", fourcc, 30, Size(w, h));
                if (!cap.isOpened()) {
                    cerr << "File open failed!" << endl;
                    return -1;
                }   
            }
            recoding = true;
            cout << "실행" << endl;
        }
        if (key == 'e') {
            if (recoding) {
                recoding = false;
                cout << "종료" << endl;
                break;
            }
        }
        if (recoding) {
            outputVideo << frame;
        }
    }
    return 0;
}
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main() {
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cerr << "Camera open failed!" << endl;
        return -1;
    }
    int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
    int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
    int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');
    VideoWriter outputVideo;
    bool isRecording = false;
    Mat frame;
    while (true) {
        cap >> frame;
        if (frame.empty()) break;
        imshow("Camera", frame);
        char key = waitKey(30);
        if (key == 's') {
            if (!isRecording) {
                outputVideo.open("output.avi", fourcc, 30, Size(w, h));
                if (!outputVideo.isOpened()) {
                    cerr << "VideoWriter open failed!" << endl;
                    return -1;
                }
                isRecording = true;
                cout << "Recording started!" << endl;
            }
        }
        if (key == 'e') {
            if (isRecording) {
                outputVideo.release();
                cout << "Recording stopped!" << endl;
            }
            break;
        }
        if (isRecording) {
            outputVideo << frame;
        }
    }
    return 0;
}

#include <opencv2/opencv.hpp>  
#include <iostream>            
using namespace cv;
using namespace std;
int main() {
    Mat img(400, 400, CV_8UC3, Scalar(255, 255, 255));
    line(img, Point(100, 100), Point(100, 300), Scalar(0, 0, 0));
    line(img, Point(100, 100), Point(300, 100), Scalar(0, 0, 0));
    line(img, Point(100, 300), Point(300, 300), Scalar(0, 0, 0));
    line(img, Point(300, 100), Point(300, 300), Scalar(0, 0, 0));
    line(img, Point(100, 100), Point(300, 300), Scalar(0, 0, 0));
    line(img, Point(100, 300), Point(300, 100), Scalar(0, 0, 0));
    imshow("img", img);
    waitKey();
    return 0;
}
