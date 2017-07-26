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
    unsigned int id;
    unsigned long frameId;
    Vec4f endPoint;
public:
    Line();
    Line(unsigned int id_, unsigned long frameId_, Vec4f endPoint_);
    ~Line();
};
}//namespace Lslam

#endif //LINEDETECTOR_H