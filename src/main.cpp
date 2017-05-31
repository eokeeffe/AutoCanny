#include <iostream>
#include <cmath>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <auto_canny.h>



int main(int argc,char *argv[])
{
    cv::Mat src=cv::imread(argv[1]),dst;
    auto_canny(src,dst,0.33);
    cv::imwrite("auto_canny.jpg",dst);
    return 0;
}

