#include"Frame.h"

namespace Lslam{

void Frame::getAllLines(Mat color){
    Ptr<LineSegmentDetector> ls = createLineSegmentDetector(LSD_REFINE_ADV);
    double start = double(getTickCount());
    vector<Vec4f> lines_std;
    // Detect the lines
    ls->detect(color, lines_std);
    double duration_ms = (double(getTickCount()) - start) * 1000 / getTickFrequency();
    std::cout << "It took " << duration_ms << " ms." << std::endl;
    // Show found lines
    Mat drawnLines(color);
    ls->drawSegments(drawnLines, lines_std);
    imshow("Standard refinement", drawnLines);
     waitKey(10);
}
}