#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <time.h>
#include <vector>

using namespace cv;

void applyLaplace1(Mat img){
    int kern[] = {  1, 1, 1, 
                    1, -8, 1, 
                    1, 1, 1};
    cv::Mat kernal = cv::Mat(cv::Size(3,3), CV_8UC1, kern);
    img.convertTo(img, CV_64FC1);
    cv::filter2D(img, img, -1, kernal);
    img.convertTo(img, CV_16UC1);
    cv::imwrite("laplace_out1.tif", img);
}
void applyLaplace2(Mat img){
    int kern[] = {  1, 1, 1, 
                    1, 1, 1, 
                    1, 1, 1};
    cv::Mat kernal = cv::Mat(cv::Size(3,3), CV_8UC1, kern);
    img.convertTo(img, CV_64FC1);
    cv::filter2D(img, img, -1, kernal);
    img.convertTo(img, CV_16UC1);
    cv::imwrite("laplace_out2.tif", img);
    std::cout << "Type of image: " << img.type() << std::endl;
}


int main(){
    cv::Mat img = cv::imread("/full/file/path.tif", -1);
    applyLaplace1(img);
    applyLaplace2(img);
    return 0;

}