#include <iostream>
const size_t MAX_MATRIX_SIZE = 128;

void innitMatrix(int matrix[][MAX_MATRIX_SIZE], const unsigned size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
}

void indexAtMatrix(int matrix[][MAX_MATRIX_SIZE], const unsigned size, const int seekedNumber)
{
    bool found = false;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (matrix[i][j] == seekedNumber)
            {
                found = true;
                matrix[i][j] *= 10;
                std::cout << "Seeked number, found at row: " << i << ", and column : " << j << std::endl;
            }
        }
    }
    if (found == false)
        std::cout << "Seeked number was not found in matrix!" << std::endl;
}

void printMatrix(int matrix[][MAX_MATRIX_SIZE], const unsigned size)
{
    std::cout << "Printing matrix" << std::endl;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    unsigned size;
    int seekedNumber;
    std::cout << "Please enter matrix dimensions" << std::endl;
    std::cin >> size;
    int matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
    innitMatrix(matrix, size);
    std::cout << "Please enter searched number: " << std::endl;
    std::cin >> seekedNumber;
    indexAtMatrix(matrix, size, seekedNumber);
    std::cout << std::endl;
    printMatrix(matrix, size);

    return 0;
}