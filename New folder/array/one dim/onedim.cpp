// One-Dimensional Array:
//A one-dimensional array is a collection of elements arranged in a single row. It's like a list of items where each item has a unique index.


#include <iostream>

int main() {
    // One-dimensional array declaration and initialization
    int numbers[5] = {10, 20, 30, 40, 50};

    // Accessing elements of the array
    std::cout << "Third element: " << numbers[2] << std::endl; // Output: 30

    return 0;
}
In this example, numbers is a one-dimensional array with 5 elements. Each element is an integer, and we access the third element using numbers[2].