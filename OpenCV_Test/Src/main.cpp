#include <iostream>
#include <opencv2/opencv.hpp>
#include <fmt/core.h>
#include "image_utils.hpp"

int main() {
    // 1. 读取输入图像 (请根据实际情况替换路径)
    cv::Mat src = cv::imread("屏幕截图 2026-07-13 194249.png");
    if (src.empty()) {
        std::cerr << "无法读取图像！" << std::endl;
        return -1;
    }

    double scale = 0.0;
    int pad_w = 0;
    int pad_h = 0;

    // 2. 调用外部分离的缩放函数，目标尺寸设为 640 * 640
    cv::Mat dst = resizeLetterbox(src, 640, 640, scale, pad_w, pad_h);

    // 3. 使用 fmt 输出缩放比例和偏移距离等参数
    fmt::print("图像处理完成：\n");
    fmt::print(" - 缩放比例 (Scale) : {:.4f}\n", scale);
    fmt::print(" - X轴偏移距离 (Pad X): {} 像素\n", pad_w);
    fmt::print(" - Y轴偏移距离 (Pad Y): {} 像素\n", pad_h);

    // [可选] 显示结果验证
    cv::imshow("Original", src);
    cv::imshow("Result 640x640", dst);
    cv::waitKey(0);

    return 0;
}