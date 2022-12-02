#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <time.h>

using namespace cv;

void printImage(cv::Mat& img){
    clock_t s_time = clock();
    std::cout << "type of image:  " << img.type() << std::endl;
    cv::Vec3b img_temp(255, 255, 255);
    img = img_temp - img;
    // for(int row = 0 ; row < img.rows ; ++row){
    //     for(int col = 0 ; col < img.cols ; ++col){
    //         cv::Vec3b &pix = img.at<cv::Vec3b> (row, col);
    //         pix[0] = 255 - pix[0];
    //         pix[1] = 255 - pix[1];
    //         pix[2] = 255 - pix[2];
    //     }
    // }
    std::cout << "Time taken : " << clock() - s_time << std::endl;

}


int main(){
    cv::Mat img = cv::imread("file/path.tif", -1);
    printImage(img);
    return 0;

}