#include"Line.h"

namespace Lslam{

Line::Line(){}
Line::Line(unsigned int lineId, unsigned long parentFrameId, Vec4f endPoint){
    mlineId = lineId;
    mparentFrameId = parentFrameId;
    mendPoint = endPoint;
}
Line::~Line(){}

}