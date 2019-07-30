/******************************************************************************
 * Copyright 2019 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#pragma once

#include <algorithm>
#include <limits>
#include <memory>
#include <utility>
#include <vector>

#include "Eigen/Eigen"
#include "cyber/common/log.h"
#include "osqp/include/osqp.h"

namespace apollo {
namespace common {
namespace math {
class MpcOsqp {
 public:
  /**
   * @brief Solver for discrete-time model predictive control problem.
   * @param matrix_a The system dynamic matrix
   * @param matrix_b The control matrix
   * @param matrix_q The cost matrix for control state
   * @param matrix_lower The lower bound control constrain matrix
   * @param matrix_upper The upper bound control constrain matrix
   * @param matrix_initial_state The initial state matrix
   * @param max_iter The maximum iterations
   */
  MpcOsqp(const Eigen::MatrixXd &matrix_a, const Eigen::MatrixXd &matrix_b,
          const Eigen::MatrixXd &matrix_q, const Eigen::MatrixXd &matrix_r,
          const Eigen::MatrixXd &matrix_lower,
          const Eigen::MatrixXd &matrix_upper,
          const Eigen::MatrixXd &matrix_initial_state, const int max_iter);

  // control vector
  bool MpcOsqpSolver(std::vector<double> *control_cmd);

 private:
  void CalculateKernel(std::vector<c_float> *P_data,
                       std::vector<c_int> *P_indices,
                       std::vector<c_int> *P_indptr);
  void CalculateEqualityConstraint(std::vector<c_float> *A_data,
                                   std::vector<c_int> *A_indices,
                                   std::vector<c_int> *A_indptr);
  void castMPCToQPGradient();
  void castMPCToQPConstraintMatrix();
  void castMPCToQPConstraintVectors();
  OSQPSettings *Settings();
  OSQPData *Data();
  void FreeData(OSQPData *data);

  template <typename T>
  T *CopyData(const std::vector<T> &vec) {
    T *data = new T[vec.size()];
    memcpy(data, vec.data(), sizeof(T) * vec.size());
    return data;
  }

 private:
  Eigen::MatrixXd matrix_a_;
  Eigen::MatrixXd matrix_b_;
  Eigen::MatrixXd matrix_q_;
  Eigen::MatrixXd matrix_r_;
  int max_iteration_;
  int num_constraint_;
  int num_param_;
  int state_dim_;
  int horizon_;
  int control_dim_;
  Eigen::VectorXd gradient_;
  Eigen::VectorXd lowerBound_;
  Eigen::VectorXd upperBound_;
  Eigen::MatrixXd matrix_initial_state_;
  Eigen::MatrixXd matrix_lower_;
  Eigen::MatrixXd matrix_upper_;
};
}  // namespace math
}  // namespace common
}  // namespace apollo