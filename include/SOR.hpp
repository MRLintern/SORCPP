// function for implementing the SOR algorithm

#pragma once

#include <Eigen/Dense>

Eigen::VectorXd SOR(const Eigen::MatrixXd& A, const Eigen::VectorXd& b, double relaxFactor, int maxIterations, double tolerance);
