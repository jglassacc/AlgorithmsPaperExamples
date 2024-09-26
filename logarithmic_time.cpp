#include <iostream>
#include <vector>

int binarySearch(const std::vector<int> &vec, int target)
{
    int left = 0;
    int right = vec.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (vec[mid] == target)
        {
            return mid; // Target found, return index
        }
        else if (vec[mid] < target)
        {
            left = mid + 1; // Move to the right half
        }
        else
        {
            right = mid - 1; // Move to the left half
        }
    }

    return -1; // Target not found
}

int main()
{
    std::vector<int> sortedArray = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int target = 14;

    int result = binarySearch(sortedArray, target);

    if (result != -1)
    {
        std::cout << "Element found at index " << result << std::endl;
    }
    else
    {
        std::cout << "Element not found in the array." << std::endl;
    }

    return 0;
}