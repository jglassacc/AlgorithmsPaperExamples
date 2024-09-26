#include <iostream>
#include <vector>
#include <algorithm>

void printPermutation(const std::vector<int> &permutation)
{
    for (int num : permutation)
    {
        std::cout << num << " ";
    }

    std::cout << std::endl;
}

void generatePermutations(std::vector<int> &vec, int l, int r)
{
    if (l == r)
    {
        printPermutation(vec);
    }
    else
    {
        for (int i = l; i <= r; ++i)
        {
            std::swap(vec[l], vec[i]);

            generatePermutations(vec, l + 1, r);

            std::swap(vec[l], vec[i]); // backtrack
        }
    }
}

int main()
{
    std::vector<int> array = {1, 2, 3};

    generatePermutations(array, 0, array.size() - 1);

    return 0;
}