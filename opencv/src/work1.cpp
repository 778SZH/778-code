#include "work1.hpp"

namespace work1 {

int PictureViewer(const std::string& imgPath) {
    cv::Mat img = cv::imread(imgPath, cv::IMREAD_COLOR);
    if (img.empty()) {
        std::cout << "[PictureViewer] 读图失败" << std::endl;
        return -1;
    }

    printInfo("彩色原图", img);

    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    printInfo("灰度图", gray);

    if (shouldShow()) {
        cv::imshow("彩色图", img);
        cv::imshow("灰度图", gray);
        cv::waitKey(0);
    }
    return 0;
}

void FlagGenerator(const std::string& saveFileName) {
    cv::Mat flag(300, 600, CV_8UC3, cv::Scalar(0, 0, 0));

    flag(cv::Rect(0,   0, 200, 300)).setTo(cv::Scalar(255, 0, 0));
    flag(cv::Rect(200, 0, 200, 300)).setTo(cv::Scalar(0, 255, 0));
    flag(cv::Rect(400, 0, 200, 300)).setTo(cv::Scalar(0, 0, 255));

    cv::Vec3b before = flag.at<cv::Vec3b>(80, 250);
    std::cout << "修改前 (250,80) BGR = "
              << (int)before[0] << "," << (int)before[1] << "," << (int)before[2] << std::endl;

    flag.at<cv::Vec3b>(80, 250) = cv::Vec3b(255, 255, 255);

    cv::Vec3b after = flag.at<cv::Vec3b>(80, 250);
    std::cout << "修改后 (250,80) BGR = "
              << (int)after[0] << "," << (int)after[1] << "," << (int)after[2] << std::endl;

    if (shouldShow()) {
        cv::imshow("三色旗", flag);
        cv::waitKey(0);
    }
    if (!saveFileName.empty()) cv::imwrite(saveFileName, flag);
}

int Cutting(const std::string& imgPath) {
    cv::Mat src = cv::imread(imgPath, cv::IMREAD_COLOR);
    if (src.empty()) { std::cout << "[Cutting] 读图失败" << std::endl; return -1; }
    if (src.cols < 300 || src.rows < 300) { std::cout << "[Cutting] 图片需 >=300x300" << std::endl; return -1; }

    cv::Rect roi(50, 80, 120, 100);

    cv::Mat imgA = src.clone();
    cv::Mat roiA = imgA(roi);
    roiA.setTo(cv::Scalar(0, 0, 0));
    cv::Scalar mA = cv::mean(imgA(roi));
    bool changedA = (mA[0] == 0 && mA[1] == 0 && mA[2] == 0);
    std::cout << "实验A（直接 ROI）原图该区域被填黑 = " << (changedA ? "是（共享内存）" : "否") << std::endl;

    cv::Mat imgB = cv::imread(imgPath, cv::IMREAD_COLOR);
    cv::Mat roiB = imgB(roi).clone();
    roiB.setTo(cv::Scalar(0, 0, 0));
    cv::Scalar mB = cv::mean(imgB(roi));
    bool changedB = (mB[0] == 0 && mB[1] == 0 && mB[2] == 0);
    std::cout << "实验B（clone()）原图该区域被填黑 = " << (changedB ? "是" : "否（独立副本，原图不变）") << std::endl;

    if (shouldShow()) {
        cv::imshow("A-直接ROI后的原图", imgA);
        cv::imshow("B-clone后的原图", imgB);
        cv::waitKey(0);
    }
    return 0;
}

int CoveredWithBlackAndWhite(const std::string& imgPath) {
    cv::Mat img = cv::imread(imgPath, cv::IMREAD_COLOR);
    if (img.empty()) { std::cout << "[CoveredWithBlackAndWhite] 读图失败" << std::endl; return -1; }

    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);

    cv::Mat t60, t120, t180;
    cv::threshold(gray, t60,  60,  255, cv::THRESH_BINARY);
    cv::threshold(gray, t120, 120, 255, cv::THRESH_BINARY);
    cv::threshold(gray, t180, 180, 255, cv::THRESH_BINARY);

    cv::Mat manual(gray.rows, gray.cols, CV_8UC1);
    long whiteCount = 0;
    for (int r = 0; r < gray.rows; ++r) {
        for (int c = 0; c < gray.cols; ++c) {
            uchar out = (gray.at<uchar>(r, c) > 120) ? 255 : 0;
            manual.at<uchar>(r, c) = out;
            if (out == 255) ++whiteCount;
        }
    }

    long total = (long)gray.rows * gray.cols;
    std::cout << "阈值120 二值图：白色像素 = " << whiteCount
              << "，占总像素 = " << (100.0 * whiteCount / total) << "%" << std::endl;

    if (shouldShow()) {
        cv::imshow("阈值60",  t60);
        cv::imshow("阈值120", t120);
        cv::imshow("阈值180", t180);
        cv::imshow("手动循环阈值120", manual);
        cv::waitKey(0);
    }
    return 0;
}

int Progression(const std::string& imgPath) {
    cv::Mat img = cv::imread(imgPath, cv::IMREAD_COLOR);
    if (img.empty()) { std::cout << "[Progression] 读图失败" << std::endl; return -1; }

    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);

    cv::Mat mean, gauss, median;
    cv::blur(gray, mean, cv::Size(3, 3));
    cv::GaussianBlur(gray, gauss, cv::Size(3, 3), 0);
    cv::medianBlur(gray, median, 3);

    cv::Mat c1, c2, c3, c4;
    cv::Canny(gray,  c1, 50,  100);
    cv::Canny(gray,  c2, 100, 200);
    cv::Canny(gauss, c3, 50,  100);
    cv::Canny(gauss, c4, 100, 200);

    if (shouldShow()) {
        cv::imshow("原灰度图", gray);
        cv::imshow("均值滤波", mean);
        cv::imshow("高斯滤波", gauss);
        cv::imshow("中值滤波", median);
        cv::imshow("Canny 灰度 (50,100)",   c1);
        cv::imshow("Canny 灰度 (100,200)",  c2);
        cv::imshow("Canny 高斯 (50,100)",   c3);
        cv::imshow("Canny 高斯 (100,200)",  c4);
        cv::waitKey(0);
    } else {
        std::cout << "[Progression] 完成：已生成 3 种滤波 + 4 张 Canny 结果" << std::endl;
    }
    return 0;
}

int RealtimeCamera(int cameraID) {
    cv::VideoCapture cap(cameraID);
    if (!cap.isOpened()) { std::cout << "[RealtimeCamera] 打不开摄像头" << std::endl; return -1; }

    char mode = '1';
    cv::Mat frame;
    while (true) {
        cap >> frame;
        if (frame.empty()) break;

        cv::Mat out;
        switch (mode) {
        case '1': out = frame; break;
        case '2': cv::cvtColor(frame, out, cv::COLOR_BGR2GRAY); break;
        case '3': {
            cv::Mat g; cv::cvtColor(frame, g, cv::COLOR_BGR2GRAY);
            cv::threshold(g, out, 120, 255, cv::THRESH_BINARY);
            break;
        }
        case '4': {
            cv::Mat g; cv::cvtColor(frame, g, cv::COLOR_BGR2GRAY);
            cv::Canny(g, out, 50, 100);
            break;
        }
        }

        cv::imshow("摄像头 (1原图 2灰度 3二值 4Canny q退出)", out);
        char key = (char)cv::waitKey(1);
        if (key == 'q') break;
        if (key >= '1' && key <= '4') mode = key;
    }
    return 0;
}

}
