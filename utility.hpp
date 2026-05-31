#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <cassert>
#include <vector>

/**
 * @brief Scalar product of two vectors.
 * @tparam T Element type supporting multiplication and addition.
 * @param vec1 First vector.
 * @param vec2 Second vector.
 * @return Sum of element-wise products.
 */
template <typename T>
T operator*(const std::vector<T>& vec1, const std::vector<T>& vec2)
{
    assert(vec1.size() == vec2.size() && "Vector size mismatch!");
    T res{};
    for (std::size_t i = 0, n = vec1.size(); i < n; ++i) {
        res += vec1[i] * vec2[i];
    }

    return res;
}

#endif
