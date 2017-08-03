#ifndef SYSTEM_H
#define SYSTEM_H

#include<string>

#include"Line.h"
#include"Frame.h"

namespace Lslam{

class System{
public:
    System(const string &strSettingFile);
    void test();
private:
    //相机参数
    //focal length
    float fx;
    float fy;
    //center
    float cx;
    float cy;
    //distortion
    float k1;
    float k2;
    float p1;
    float p2;
    
    float fps;

};

}
#endif  //SYSTEM_H