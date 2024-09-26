#include <iostream>
#include <vector>

int sumArray(const std::vector<int> &vec)
{
    int sum = 0;

    for (int num : vec)
    {
        sum += num; // Add each element to the sum
    }

    return sum;
}

int main()
{
    std::vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int result = sumArray(array);

    std::cout << "The sum of the array elements is " << result << std::endl;

    return 0;
}