#include <iostream>

int main()
{
    int array[] = {10, 20, 30, 40, 50};
    int index = 3;

    // Accessing an element at a specific index (O(1))
    int value = array[index];

    std::cout << "The element at index " << index << " is " << value << std::endl;

    return 0;
}