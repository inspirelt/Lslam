#ifndef LINE_H
#define LINE_H
/*
*这个模块掌管每条线段的属性以及用处
*/
#include<iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

using namespace std;
using namespace cv;

namespace Lslam{
class Line{
public:
    unsigned int mlineId;
    unsigned long mparentFrameId;
    Vec4f mendPoint;
public:
    Line();
    Line(unsigned int lineId, unsigned long parentFrameId, Vec4f endPoint);
    ~Line();
};
}//namespace Lslam

#endif //LINEDETECTOR_H