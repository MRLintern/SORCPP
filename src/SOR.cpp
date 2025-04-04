// driver for SOR algorithm and time for convergence

#include <iostream>
#include <Eigen/Dense>
#include <chrono>
#include "SOR.hpp"

// function for implementing SOR algorithm
Eigen::VectorXd SOR(const Eigen::MatrixXd& A, const Eigen::VectorXd& b, double relaxFactor, int maxIterations, double tolerance) {

    // number of rows of matrix A
    int n = A.rows();

    // column x vector; elements to be found; initially 0
    Eigen::VectorXd x = Eigen::VectorXd::Zero(n);  

    // column x vector; previous values
    Eigen::VectorXd x_previous(n);

    // Start timing
    auto start {std::chrono::high_resolution_clock::now()};

    for (int k {0}; k < maxIterations; ++k) {

        x_previous = x;  // Store previous iteration values

        for (int i {0}; i < n; ++i) {

            double summation {0.0}; // this is the Greek symbol for summation, sigma

            // Compute summation for known values (Gauss-Seidel update)
            for (int j {0}; j < i; ++j) {

                summation += A(i, j) * x(j);  // Updated values; summation (Ax)
            }

            for (int j {i + 1}; j < n; ++j) {

                summation += A(i, j) * x_previous(j);  // Old values
            }

            // Compute new value with relaxation
            x(i) = (1 - relaxFactor) * x_previous(i) + (relaxFactor / A(i, i)) * (b(i) - summation);
        }

        // Check for convergence; uses Euclidean norm; p = 2
        if ((x - x_previous).norm() < tolerance) {

            // stop timing
            auto end {std::chrono::high_resolution_clock::now()};

            // compute elapsed time
            double elapsed_time {std::chrono::duration<double>(end - start).count()};

            // how many iterations algorithm took to converge
            std::cout<<"Converged in "<<k + 1<<" iterations.\n";

            // how long it took to converge
            std::cout<<"Time taken: "<< elapsed_time<<" seconds.\n";

            return x;
        }
    }

    // If max iterations reached, still measure time; end time
    auto end {std::chrono::high_resolution_clock::now()};

    // total time taken for convergence
    double elapsed_time {std::chrono::duration<double>(end - start).count()};
    
    std::cout<<"Reached maximum iterations without full convergence.\n";
    std::cout<<"Time taken: " << elapsed_time<<" seconds.\n";
    
    return x;
}
