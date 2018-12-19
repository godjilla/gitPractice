/**
 * @file Evaluation.h
 * @brief Helper function for evaluating trajectories
 * @author Jinwoo Choi
 * @email jinwoos.choi@samsung.net
 *
 * @date 2018
 */

#ifndef _VISION_TOOLS_EVALUATION_H_
#define _VISION_TOOLS_EVALUATION_H_

#include <vector>

#include <opencv2/opencv.hpp>

using namespace std;

class Evaluation {
 public:
  static void EvaluateTrajectory(vector<cv::Mat>& poseGT, vector<cv::Mat>& poseTest);
};

#endif
