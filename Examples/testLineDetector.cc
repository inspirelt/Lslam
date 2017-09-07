#include<iostream>
#include<opencv2/core/core.hpp>
#include"Frame.h"
#include"System.h"

using namespace std;
using namespace Lslam;
using namespace cv;

int main(int argc,char** argv){

    if(argc != 3){
	cout<<"Error parameters! Usage:testLineDetector videoName settingFile."<<endl;
	return 0;
    }
    VideoCapture capture(argv[1]);
    Mat color = Mat();
    Frame frame;
    if(!capture.isOpened())
        cout<<"fail to open~"<<endl;
    long totalFrameNumber = capture.get(CV_CAP_PROP_FRAME_COUNT);
    cout<<"total "<<totalFrameNumber<<" frames "<<endl;
    bool stop = false;
    int id = 0;
    // vector<Line> temp;

    System y = System(argv[2]);

    while(!stop){
        if(!capture.read(color)){
            cout<<"read failed~"<<endl;
            return -1;
        }
        cvtColor(color,color,COLOR_BGR2GRAY);
        frame = Frame(id++,color);
        frame.ExtractLines();
        vector<Line> lines = frame.getCurrentFrameLines();
        for(vector<Line>::iterator vit = lines.begin(),vend = lines.end();vit!=vend;vit++){
            cout<<"| frame : "<<(*vit).mparentFrameId<<" | lineId : "<<(*vit).mlineId<<" | point : "<<(*vit).mendPoint<<endl;
        }

    }

    // Mat img = imread("../data/eigenfaces.png",IMREAD_GRAYSCALE);
    
    // frame.getAllLines(img);

    return 0;
}
