//Two-Dimensional Array:
//A two-dimensional array is like a table with rows and columns. Each element in a two-dimensional array is identified by two indices.


#include <iostream>

int main() {
    // Two-dimensional array declaration and initialization
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // Accessing elements of the array
    std::cout << "Element at (1, 2): " << matrix[1][2] << std::endl; // Output: 6

    return 0;
}