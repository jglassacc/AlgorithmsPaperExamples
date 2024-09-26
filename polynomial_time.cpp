#include <iostream>
#include <vector>

void multiplyMatrices(const std::vector<std::vector<int>> &matA, const std::vector<std::vector<int>> &matB, std::vector<std::vector<int>> &result)
{
    int n = matA.size();

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            result[i][j] = 0;

            for (int k = 0; k < n; ++k)
            {
                result[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
}

int main()
{
    std::vector<std::vector<int>> matA = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    std::vector<std::vector<int>> matB = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}};

    int n = matA.size();

    std::vector<std::vector<int>> result(n, std::vector<int>(n));

    multiplyMatrices(matA, matB, result);

    std::cout << "Resultant matrix: " << std::endl;

    for (const auto &row : result)
    {
        for (int val : row)
        {
            std::cout << val << " ";
        }

        std::cout << std::endl;
    }

    return 0;
}