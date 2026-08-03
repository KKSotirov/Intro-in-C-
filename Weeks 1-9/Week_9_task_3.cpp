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

void transposeMatrix(int matrix[][MAX_MATRIX_SIZE], int resultMatrix[][MAX_MATRIX_SIZE], const unsigned size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            resultMatrix[i][j] = matrix[j][i];
        }
    }
}

void printMatrix(int matrix[][MAX_MATRIX_SIZE], const unsigned size)
{
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
    std::cout << "Please enter matrix dimensions" << std::endl;
    std::cin >> size;
    int matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
    innitMatrix(matrix, size);
    int resultMatrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
    transposeMatrix(matrix, resultMatrix, size);
    std::cout << std::endl;
    printMatrix(resultMatrix, size);

    return 0;
}