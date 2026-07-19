#pragma once

#include <opencv2/opencv.hpp>

// 函数声明：对图像进行等比例缩放居中和黑边填充
// 返回处理后的图像，并通过引用传出缩放比例和偏移距离
cv::Mat resizeLetterbox(const cv::Mat& src, int target_w, int target_h, double& scale, int& pad_w, int& pad_h);

