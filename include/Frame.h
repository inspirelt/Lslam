/*
这个模块掌管每一帧的功能，包括线段的提取，其余功能后期再添加
*/
#ifndef FRAME_H
#define FRAME_H

#include<iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include"Line.h"

using namespace cv;
using namespace std;
namespace Lslam{
class Line;
class Frame{
private:
    // typedef shared_ptr<Frame> Ptr;
    vector<Line*> mvpLines_;
    unsigned long id_;
    Mat color_;
public:
    Frame(){};
    Frame(long id,Mat color = Mat()){id_=id;}
    void ExtractLines(const Mat &color , vector<Line*> );
    ~Frame(){};
}; 
}


#endif  //FRAME_H