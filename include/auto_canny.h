#ifndef __AUTO_CANNY__
#define __AUTO_CANNY__

#include <algorithm>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

double medianMat(cv::Mat Input);
cv::Mat auto_canny(cv::Mat &image,cv::Mat &output,float sigma);

double medianMat(cv::Mat Input)
{
    Input = Input.reshape(0,1);// spread Input Mat to single row
    std::vector<double> vecFromMat;
    Input.copyTo(vecFromMat); // Copy Input Mat to vector vecFromMat
    std::nth_element(vecFromMat.begin(), vecFromMat.begin() + vecFromMat.size() / 2, vecFromMat.end());
    return vecFromMat[vecFromMat.size() / 2];
}

cv::Mat auto_canny(cv::Mat &image,cv::Mat &output,float sigma=0.33)
{
    //convert to grey colour space
    cv::cvtColor( image, output, cv::COLOR_BGR2GRAY );
    //apply small amount of Gaussian blurring
    cv::GaussianBlur( output, output, cv::Size( 3, 3), 0, 0);
    //get the median value of the matrix
    double v = medianMat(output);
    //generate the thresholds
    int lower = (int)std::max(0.0,(1,0-sigma)*v);
    int upper = (int)std::min(255.0,(1,0+sigma)*v);
    //apply canny operator
    cv::Canny(output, output, lower, upper, 3);
    return output;
}

#endif
