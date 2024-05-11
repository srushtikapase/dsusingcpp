// Three-Dimensional Array:
//A three-dimensional array is like a cube of values. It's an array of arrays of arrays, allowing you to store data in a three-dimensional grid.


#include <iostream>

int main() {
    // Three-dimensional array declaration and initialization
    int cube[2][3][4] = {
        {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}},
        {{13, 14, 15, 16}, {17, 18, 19, 20}, {21, 22, 23, 24}}
    };

    // Accessing elements of the array
    std::cout << "Element at (1, 2, 3): " << cube[1][2][3] << std::endl; // Output: 24

    return 0;
}