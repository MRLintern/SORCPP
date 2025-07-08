# SORCPP
This is a demo. of how to implement the SOR algorithm in C++

## The Successive Over Relaxation (SOR) Algorithm
### Introduction
* The ___Successive Over-Relaxation (SOR)___ method is an __iterative technique__ used to solve __systems of linear equations__, particularly those arising from the __discretization of Partial Differential Equations (PDEs)__, such as in __finite Difference__ or __Finite Element Methods__.
* The __SOR__ method __accelerates__ the __Convergence__ of the __Gauss-Seidel__ method by introducing a ___Relaxation Factor ω___, which __controls__ the __weight__ of the __update step__.

#### Parameters:
* __ω = 1__: reduces to __Gauss-Seidel__.
* __0 < ω < 1__: __under-relaxation__ (slower but more stable).
* __1 < ω < 2__: __over-relaxation__ (__faster convergence__, but can diverge if __ω__ is too large).

#### Convergence:
* __SOR__ converges faster than __Gauss-Seidel__ when __ω__ is chosen optimally.
* Best suited for __Symmetric Positive-Definite__ or __Diagonally Dominant Matrices__.
* Convergence depends on the ___Spectral Radius___ of the __Iteration Matrix__; ideally, choose __ω__ to minimize it.

### Advantages:
* Faster convergence than __Jacobi__ and __Gauss-Seidel__ methods when tuned properly.
* Useful for __Sparse Systems__ arising in PDEs.

### Disadvantages:
* Requires careful tuning of __ω__.
* __Not guaranteed__ to converge for all systems.
* Performance degrades on modern architectures unless parallelized carefully (e.g., using ___Red-Black Ordering___ for structured grids).

## Requirements
* `Compiler`: `g++ 13.1.0`.
* `OS`: `Ubuntu 20.04`.
* `Eigen C++ Template Library`. See the [StokesianFlow](https://github.com/MRLintern/StokesianFlow) project for an overview of how to install and use this library.
* `CMake`.

## Getting and Running the Software

* `$ git clone git@github.com:MRLintern/SORCPP.git`
* `$ cd SORCPP`
* `$ mkdir build -p && cd build`
* `$ cmake ..`
* `$ cmake --build .`
* `$ ./SORCPP`


