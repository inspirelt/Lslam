#include"Frame.h"

namespace Lslam{

Frame::Frame(long frameId, Mat color){
    mframeId = frameId;
    mcolor = color.clone();
}
void Frame::ExtractLines(const Mat &color){
    static unsigned int id = 0;
    unsigned long frameId= 1;
    Ptr<LineSegmentDetector> ls = createLineSegmentDetector(LSD_REFINE_ADV);
    vector<Vec4f> lines_std;
    ls->detect(color, lines_std);
    for(vector<Vec4f>::iterator vit=lines_std.begin(),vend=lines_std.end();vit!=vend;vit++){
            Line pLine = Line(id++, frameId, *vit);
            mvLines.push_back(pLine);
    }
    Mat drawnLines(color);
    ls->drawSegments(drawnLines,lines_std);
    imshow("draw segments",drawnLines);
    waitKey(10);
}
// void Frame::getAllLines(Mat color){
//     Ptr<LineSegmentDetector> ls = createLineSegmentDetector(LSD_REFINE_ADV);
//     double start = double(getTickCount());
//     vector<Vec4f> lines_std;
//     // Detect the lines
//     ls->detect(color, lines_std);
//     double duration_ms = (double(getTickCount()) - start) * 1000 / getTickFrequency();
//     std::cout << "It took " << duration_ms << " ms." << std::endl;
//     // Show found lines
//     Mat drawnLines(color);
//     ls->drawSegments(drawnLines, lines_std);
//     imshow("Standard refinement", drawnLines);
//      waitKey(10);
// }
}