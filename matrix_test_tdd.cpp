#include "matrix.hpp"
#include "utility.hpp"
#include <gtest/gtest.h>
#include <cstddef>



TEST(MatrixCheck, DefineEmptyMatrix)
{
    std::size_t M = 5, N = 7;
    Matrix<int> mi(M, N);
    Matrix<float> mf(M, N);
}

TEST(MatrixCheck, CheckDefaultMatrix)
{
    Matrix<int> mi;

    EXPECT_EQ(mi.getRows(), 0);
    EXPECT_EQ(mi.getCols(), 0);
}

TEST(MatrixCheck, CheckMatrixSize)
{
    std::size_t M = 5, N = 7;
    Matrix<float> mf(M, N);

    EXPECT_EQ(mf.getRows(), M);
    EXPECT_EQ(mf.getCols(), N);
}

TEST(MatrixCheck, CheckMatrixRowObjectSize)
{
    std::size_t M = 5, N = 7;
    Matrix<int> mi(M, N);
    
    EXPECT_EQ(mi[3].size(), N);
}

TEST(MatrixCheck, CheckAccessOperator)
{
    std::size_t M = 5, N = 7;
    Matrix<float> mf(M, N);
    mf[0][0] = 2.0;
    mf[3][4] = 1.0f;
    
    EXPECT_EQ(mf[0][0], 2.0);
    EXPECT_EQ(mf[4][3], 0.0);
    EXPECT_EQ(mf[3][4], 1.0f);
}

TEST(MatrixCheck, CheckMatrixNoRowConstruction)
{
    std::size_t M = 0, N = 5;
    Matrix<int> m(M, N);

    EXPECT_EQ(m.getRows(), M);
    EXPECT_EQ(m.getCols(), N);
}

TEST(MatrixCheck, CheckMatrixNoColumnConstruction)
{
    std::size_t M = 7, N = 0;
    Matrix<int> m(M, N);

    EXPECT_EQ(m.getRows(), M);
    EXPECT_EQ(m.getCols(), N);
}

TEST(MatrixCheck, CheckCopyConstruction)
{
    std::size_t M = 3, N = 5;
    Matrix<int> m(M, N);
    for (std::size_t  i = 0; i < M; ++i) {
        for (std::size_t  j =0; j < N; ++j) {
            m[i][j] = i * j + j + j;
        }
    }

    Matrix<int> m_copy(m);
    for (std::size_t  i = 0; i < M; ++i) {
        for (std::size_t  j =0; j < N; ++j) {
            EXPECT_EQ(m_copy[i][j], m[i][j]);
        }
    }
}

TEST(MatrixCheck, CheckMoveConstruction)
{
    std::size_t M = 3, N = 5;
    Matrix<int> m(M, N);
    for (std::size_t i = 0; i < M; ++i) {
        for (std::size_t  j =0; j < N; ++j) {
            m[i][j] = i * j + i + j;
        }
    }

    Matrix<int> m_move(std::move(m));
    for (std::size_t i = 0; i < M; ++i) {
        for (std::size_t j =0; j < N; ++j) {
            EXPECT_EQ(m_move[i][j], i * j + i + j);
        }
    }

    EXPECT_EQ(m.getRows(), M);
    EXPECT_EQ(m.getCols(), N);
}

TEST(MatrixCheck, CheckMatrixMultiplication)
{
    std::size_t M = 3, N = 5, P = 4;
    Matrix<float> m(M, N);
    for (std::size_t i = 0; i < M; ++i) {
        for (std::size_t  j =0; j < N; ++j) {
            m[i][j] = i * 0.1 + j * 0.2;
        }
    }

    Matrix<float> n(N, P);
    for (std::size_t i = 0; i < N; ++i) {
        for (std::size_t  j =0; j < P; ++j) {
            n[i][j] = i * 0.3 + j * 0.4;
        }
    }

    Matrix<float> p = m * n;

    std::vector<float> n_col(N);
    for (std::size_t i = 0; i < N; ++i) {
        n_col[i] = n[i][3];
    }
    
    EXPECT_NEAR(p[2][3], m[2] * n_col, 1e-5f);
}

TEST(MatrixCheck, CheckMatrixTranspose)
{
    std::size_t M = 3, N = 5;
    Matrix<int> m(M, N);
    for (std::size_t i = 0; i < M; ++i) {
        for (std::size_t  j =0; j < N; ++j) {
            m[i][j] = i * j  + i + j;
        }
    }

    Matrix<int> t = m.transposed();

    for (std::size_t i = 0; i < M; ++i) {
        for (std::size_t  j =0; j < N; ++j) {
            EXPECT_EQ(m[i][j], t[j][i]);
        }
    }
}
