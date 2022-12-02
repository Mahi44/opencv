#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>

void applySobel(cv::Mat img, cv::Mat ele){
    cv::Mat img_out;
    int ddepth = -1;

    cv::filter2D(img, img_out, ddepth, ele);
    cv::imshow("outimg", img_out);
    cv::waitKey(0);
}

void printMat(cv::Mat ele){
    for(int i = 0 ; i < ele.rows ; i++){
        for(int j = 0 ; j < ele.cols ; j++){
            std::cout << ele.at<int>(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

cv::Mat getHKernal(){
    int kern_size = 3;
    int *data = new int[9];
    data[0] = -3;
    data[1] = 0;
    data[2] = 3;
    data[3] = -10;
    data[4] = 0;
    data[5] = 10;
    data[6] = -3;
    data[7] = 0;
    data[8] = 3;
    cv::Mat ele = cv::Mat(kern_size, kern_size, CV_32SC1, data);
    return ele;
}

cv::Mat getVKernal(){
    int kern_size = 3;
    int *data = new int[9];
    data[0] = -3;
    data[1] = -10;
    data[2] = 3;
    data[3] = 0;
    data[4] = 0;
    data[5] = 0;
    data[6] = -3;
    data[7] = -10;
    data[8] = 3;
    cv::Mat ele = cv::Mat(kern_size, kern_size, CV_32SC1, data);
    return ele;
}

void applySobel(std::string img_path){
    cv::Mat img = cv::imread(img_path, 0);
    img.convertTo(img, CV_32F);
    img = img / 255.0f;
    cv::Mat gaussian_img;
    cv::Size ksize_1(5, 5);
    double sigma = 5;
    cv::GaussianBlur(img, gaussian_img, ksize_1, sigma);

    cv::Mat grad_x, grad_y, grad_x_1, grad_x_2, grad_y_1, grad_y_2;;

    int scale = 1;
    int delta = 0;
    int ddepth = CV_32FC1;

    /// Gradient X - vertical edges
    Sobel(gaussian_img, grad_x, ddepth, 1, 0, 3, scale, delta, cv::BORDER_DEFAULT);
    grad_x_1 = grad_x;
    grad_x_2 = -grad_x;

    /// Gradient Y - horizontal edges
    Sobel(gaussian_img, grad_y, ddepth, 0, 1, 3, scale, delta, cv::BORDER_DEFAULT);
    grad_y_1 = cv::max(grad_y, 0);  // top edge
    grad_y_2 = cv::max(-grad_y, 0); // bottom edge
    cv::imshow("grad_x_1", grad_x_1);
    cv::imshow("grad_x_2", grad_x_2);
    cv::imshow("grad_y_1", grad_y_1);
    cv::imshow("grad_y_2", grad_y_2);
    cv::waitKey(0);
}

void applyMySobel(std::string img_path){
    cv::Mat img = cv::imread(img_path, 0);
    cv::Mat kern = getHKernal();
    printMat(kern);
    applySobel(img, kern);
    // delete[](int *)img.data;

    kern = getVKernal();
    printMat(kern);
    applySobel(img, kern);
    // delete[](int *)img.data;
}

int main(){
    std::string img_path = "file path";
    applySobel(img_path);

    return 0;
}