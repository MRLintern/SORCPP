// program shows how to implement the Successive Over Relaxation (SOR) algorithm using C++ and the Eigen library
// the program also shows how quickly the algorithm converges.
// the linear algebraic system to be solved is Ax = b, where A is a 3 x 3 matrix, and x & b are both 1 x 3 column vectors
// both A and b are known; the purpose is to find the solution to the system; i.e. find the 3 elements of vector x

#include <iostream>
#include <Eigen/Dense>
#include "SOR.hpp"

int main() {

	// matrix A
	Eigen::MatrixXd A {

		{4, -1, 0},
		{-1, 4, -1},
		{0, -1, 4},
	};

	// column vector b
	Eigen::VectorXd b {{15, 10, 10}};

	// Relaxation factor (values are usually chosen between 1.1 - 1.9; chosen experimentally)
	// double relaxFactor {1.0}; // the method then reduces to the Gauss-Seidel method
	double relaxFactor {1.25};

	// max. iterations to perform
	int maxIterations {1000};

	// level of error that is acceptable
	double tolerance {1e-6};

	// call the SOR function and find the elements of the vector x
	Eigen::VectorXd xVectorElements = SOR(A, b, relaxFactor, maxIterations, tolerance);

	// output solution
	std::cout<<"--------\n";
	std::cout<<"Solution:\n"<<xVectorElements<<"\n";
	std::cout<<"--------\n";
	
}
