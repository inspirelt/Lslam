/*
这个模块掌管每一帧的功能，包括线段的提取，其余功能后期再添加
*/
#ifndef FRAME_H
#define FRAME_H

#include<iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "Line.h"

using namespace cv;
using namespace std;
namespace Lslam{

class Line;
class Frame{
private:
    // typedef shared_ptr<Frame> Ptr;
    //记录当前帧中所有线段
    vector<Line> mvLines;
    
    unsigned long mframeId;
    //当前帧的图像
    Mat mcolor;
    //线段的数量
    unsigned int N;
public:
    Frame(){};
    Frame(long frameId,Mat color = Mat());
    void ExtractLines();
    vector<Line> getCurrentFrameLines();
    ~Frame(){};
}; 

}


#endif  //FRAME_H