#include"Line.h"

namespace Lslam{

Line::Line(){}
Line::Line(unsigned int id_, unsigned long frameId_, Vec4f endPoint_){
    id = id_;
    frameId = frameId_;
    endPoint = endPoint_;
}
Line::~Line(){}

}