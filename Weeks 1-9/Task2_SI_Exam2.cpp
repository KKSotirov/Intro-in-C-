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

void rotateIndexes(char matrix[][MAX_MATRIX_SIZE], const size_t size)
{
    char temp[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            temp[i][j] = matrix[j][size - 1 - i];
        }
    }

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            matrix[i][j] = temp[i][j];
        }
    }
}

void rotateMatrix(char matrix[][MAX_MATRIX_SIZE], const size_t size, unsigned number_rotations)
{
    number_rotations %= 4;
    // each rotation is 90 degrees ==> 4 rotations is 360 degrees
    /* 7 2 3        3 4 7       6 2 3
       4 1 8  ~~>   2 1 2  ~~>  8 1 4
       3 2 6        6 8 3       3 2 7  */
    for (size_t i = 0; i < number_rotations; i++)
    {
        rotateIndexes(matrix, size);
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