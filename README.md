# MutEx-Matrix-Class
MutEx School — C++ Masterclass : HPC

## Description
TDD implementation of a Matrix class based on vectors.

It should support the following API:
- `Matrix<float> m(M, N), n(N, M);`
- `m[3][4] = 1.0f;`
- `Matrix<float> p = m * n;`
- `m[3] ? (within type)`    

## Build & Run tests
make run

## Structure
- `matrix_test_tdd.cpp`  — google tests (entry point)
- `matrix.hpp`           — matrix class definition
- `utility.hpp`          — implementation of scalar product of two vectors
- `makefile`             — build and run google tests
