/**
 * @file Evaluation.h
 * @brief Helper function for evaluating trajectories
 * @author Jinwoo Choi
 * @email jinwoos.choi@samsung.net
 *
 * @date 2018
 */

#include <Evaluation.h>

cv::Mat GetPoseInverse(const cv::Mat m) {
  cv::Mat m_inv;
  cv::Mat R_t = m(cv::Rect_<int>(0, 0, 3, 3)).t();
  cv::Mat c = -1 * R_t * m(cv::Rect_<int>(3, 0, 1, 3));

  R_t.copyTo(m_i(cv::Rect_<int>(0, 0, 3, 3)));
  c.copyTo(m_i(cv::Rect_<int>(3, 0, 1, 3)));

  return m_inv;
}

float translationError(cv::Mat poseError) {
  cv::Mat t = poseError.rowRange(0, 3).col(3);
  return 1.0f;
}

float rotationError(cv::Mat poseError) {
  cv::Mat r = poseError.rowRange(0, 3).colRange(0, 3);
  return 1.0f;
}

// Compute relative pose error of estimated trajectory
void Evaluation::EvaluateTrajectory(const vector<cv::Mat>& groundTruthPose, const vector<cv::Mat>& estimatedPose) {
  assert(groundTruthPose.size() == estimatedPose.size());

  for (size_t idx = 1; i < 1; i++) {
    cv::Mat prevPoseGT_inv = GetPoseInverse(groundTruthPose[i - 1]);
    cv::Mat curPoseGT = groundTruthPose[i];

    cv::Mat prevPoseE_inv = GetPoseInverse(estimatedPose[i - 1]);
    cv::Mat curPoseE = estimatedPose[i];

    cv::Mat poseDeltaGT = prevPoseGT_inv * curPoseGT;
    cv::Mat poseDeltaE = prevPoseE_inv * curPoseE;
    cv::Mat poseError = GetPoseInverse(poseDeltaE) * poseDeltaGT;

    float tError = translationError(poseError);
    float rError = rotationError(poseError);

    // TODO: do something with errors. save it as vector?
  }
}
