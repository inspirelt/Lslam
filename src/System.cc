#include"System.h"

namespace Lslam{

System::System(const string &strSettingsFile){
    cv::FileStorage fsSettings(strSettingsFile.c_str(), cv::FileStorage::READ);
    if(!fsSettings.isOpened()){
        cerr << "failed to open settings file at: "<<strSettingsFile<<endl;
        exit(-1);
    }
    float fx = fsSettings["Camera.fx"];
    float fy = fsSettings["Camera.fy"];
    float cx = fsSettings["Camera.cx"];
    float cy = fsSettings["Camera.cy"];

    float k1 = fsSettings["Camera.k1"];
    float k2 = fsSettings["Camera.k2"];
    float p1 = fsSettings["Camera.p1"];
    float p2 = fsSettings["Camera.p2"];

    float fps = fsSettings["Camera.fps"];

}
}