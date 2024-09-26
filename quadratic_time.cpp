#include <iostream>
#include <vector>

void bubbleSort(std::vector<int> &vec)
{
    int n = vec.size();

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (vec[j] > vec[j + 1])
            {
                std::swap(vec[j], vec[j + 1]); // Swap if the current element is greater than the next
            }
        }
    }
}

int main()
{
    std::vector<int> array = {64, 34, 25, 12, 22, 11, 90};

    bubbleSort(array);

    std::cout << "Sorted array: ";

    for (int num : array)
    {
        std::cout << num << " ";
    }

    std::cout << std::endl;

    return 0;
}