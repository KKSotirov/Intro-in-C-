#include <iostream>
const size_t MAX_MATRIX_SIZE = 10;

void innitMatrix(char matrix[][MAX_MATRIX_SIZE], const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
}

int main()
{
    unsigned number_rotations;
    std::cout << "Please enter number of rotations : " << std::endl;
    std::cin >> number_rotations;
    unsigned matrix_dimensions;
    std::cout << "Please enter matrix dimensions : " << std::endl;
    std::cin >> matrix_dimensions;

    char matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];

    return 0;
}