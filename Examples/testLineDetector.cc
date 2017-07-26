#include<iostream>
#include<opencv2/core/core.hpp>
#include"Frame.h"

using namespace std;
using namespace Lslam;
using namespace cv;

int main(int argc,char** argv){

    VideoCapture capture("../data/test.avi");
    Mat color = Mat();
    Frame frame = Frame();
    if(!capture.isOpened())
        cout<<"fail to open~"<<endl;
    long totalFrameNumber = capture.get(CV_CAP_PROP_FRAME_COUNT);
    cout<<"total "<<totalFrameNumber<<" frames "<<endl;
    bool stop = false;
    // vector<Line> temp;
    while(!stop){
        if(!capture.read(color)){
            cout<<"read failed~"<<endl;
            return -1;
        }
        cvtColor(color,color,COLOR_BGR2GRAY);
        frame.ExtractLines(color);
    }

    // Mat img = imread("../data/eigenfaces.png",IMREAD_GRAYSCALE);
    
    // frame.getAllLines(img);

    return 0;
}