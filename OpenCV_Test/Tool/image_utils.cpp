#include "image_utils.hpp"
#include <algorithm>
#include <cmath>

cv::Mat resizeLetterbox(const cv::Mat& src, int target_w, int target_h, double& scale, int& pad_w, int& pad_h) {
    int org_w = src.cols;
    int org_h = src.rows;

    // 计算缩放比例：取宽比和高比中较小的一个，确保图像完全放入目标尺寸内
    scale = std::min(static_cast<double>(target_w) / org_w, static_cast<double>(target_h) / org_h);

    // 计算等比例缩放后的新尺寸
    int new_w = std::round(org_w * scale);
    int new_h = std::round(org_h * scale);

    // 缩放图像
    cv::Mat resized_img;
    cv::resize(src, resized_img, cv::Size(new_w, new_h));

    // 计算中心偏移量（单侧需要填充的像素数）
    pad_w = (target_w - new_w) / 2;
    pad_h = (target_h - new_h) / 2;

    // 计算上下左右的准确填充量（防止奇数尺寸因除以2丢失1个像素）
    int top = pad_h;
    int bottom = target_h - new_h - top;
    int left = pad_w;
    int right = target_w - new_w - left;

    // 将缺失部分填充为黑色 (0, 0, 0)
    cv::Mat out_img;
    cv::copyMakeBorder(resized_img, out_img, top, bottom, left, right, cv::BORDER_CONSTANT, cv::Scalar(0, 0, 0));

    return out_img;
}