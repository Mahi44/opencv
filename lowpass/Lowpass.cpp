#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

template <typename T>
void print(const cv::Mat &img, T type){
    std::cout << "Printing img" << img.rows << ", " << img.cols << std::endl;
    for(int row = 0 ; row < img.rows ; row++){
        for(int col = 0 ; col < img.cols ;col++){
            const float &pix = img.at<float>(row, col);
            std::cout << pix << " ";
        }
        std::cout << std::endl;
    }
}

cv::Mat applyFilter(const cv::Mat &img, const cv::Mat &kernal){
    cv::Mat output;
    cv::filter2D(img, output, -1, kernal);
    return output;
}

cv::Mat applyLowPassFilter(const cv::Mat &img){
    float low_pass_kern_data[] =     {  1/9.0, 1/9.0, 1/9.0,
                                        1/9.0, 3/9.0, 1/9.0,
                                        1/9.0, 1/9.0, 1/9.0 };

    cv::Mat kernal = cv::Mat(cv::Size(3,3), CV_32FC1, low_pass_kern_data);
    cv::Mat out_img = applyFilter(img, kernal);
    cv::imwrite("./ch0_blur.tif", out_img);
    return out_img;
}

cv::Mat applySobelFilterH(const cv::Mat &img){

    float high_pass_kern_data_h[] = {   -1, 0, 1,
                                        -2, 0, 2,
                                        -1, 0, 1 };

    cv::Mat kernal = cv::Mat(cv::Size(3,3), CV_32FC1, high_pass_kern_data_h);
    cv::Mat out_img = applyFilter(img, kernal);
    cv::imwrite("./ch0_sobel_h.tif", out_img);
    return out_img;
}

cv::Mat applySobelFilterV(const cv::Mat &img){

    float high_pass_kern_data_v[] = {   -1, -2, -1,
                                        0, 0, 0,
                                        1, 2, 1 };

    cv::Mat kernal = cv::Mat(cv::Size(3,3), CV_32FC1, high_pass_kern_data_v);
    cv::Mat out_img = applyFilter(img, kernal);
    cv::imwrite("./ch0_sobel_v.tif", out_img);
    return out_img;
}

cv::Mat applySobel(const cv::Mat &img){
    cv::Mat sobel_h = applySobelFilterH(img);
    cv::Mat sobel_v = applySobelFilterV(img);
    sobel_h.convertTo(sobel_h, CV_64F);
    sobel_v.convertTo(sobel_v, CV_64F);
    cv::Mat sobel;
    cv::pow(sobel_h, 2, sobel_h);
    cv::pow(sobel_v, 2, sobel_v);
    cv::pow(sobel_v + sobel_h, 0.5, sobel);
    sobel.convertTo(sobel, CV_16U);

    cv::imwrite("sobel.tif", sobel);
    return sobel;
}


int main(){
    cv::Mat img = cv::imread("/abs/file/path.tif", -1);
    applyLowPassFilter(img);
    applySobelFilterH(img);
    applySobelFilterV(img);
    applySobel(img);
    return 0;

}