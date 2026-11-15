#pragma once
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <cstdlib>

inline bool shouldShow() {
    return std::getenv("OPENCV_NO_SHOW") == nullptr;
}

inline void printInfo(const std::string& name, const cv::Mat& img) {
    std::cout << "[" << name << "] 宽=" << img.cols
              << " 高=" << img.rows
              << " 通道数=" << img.channels()
              << " 像素总数=" << (img.rows * img.cols)
              << " 每像素字节数=" << img.elemSize() << std::endl;
}
