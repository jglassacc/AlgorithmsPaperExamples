#include <iostream>
#include <vector>

void merge(std::vector<int> &vec, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> leftArray(n1);
    std::vector<int> rightArray(n2);

    for (int i = 0; i < n1; i++)
        leftArray[i] = vec[left + i];
        
    for (int i = 0; i < n2; i++)
        rightArray[i] = vec[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (leftArray[i] <= rightArray[j])
        {
            vec[k] = leftArray[i];
            i++;
        }
        else
        {
            vec[k] = rightArray[j];
            j++;
        }

        k++;
    }

    while (i < n1)
    {
        vec[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        vec[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int> &vec, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);

        merge(vec, left, mid, right);
    }
}

int main()
{
    std::vector<int> array = {38, 27, 43, 3, 9, 82, 10};

    mergeSort(array, 0, array.size() - 1);

    std::cout << "Sorted array: ";

    for (int num : array)
    {
        std::cout << num << " ";
    }

    std::cout << std::endl;

    return 0;
}