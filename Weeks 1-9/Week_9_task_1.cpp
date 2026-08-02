#include <iostream>
const size_t MAX_ARRAY_SIZE = 128;

void innitMatrix(int matrix[][MAX_ARRAY_SIZE], const unsigned size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
    std::cout << "Matrix successfully initialized! " << std::endl;
}

void printMainDiagonal(const int matrix[][MAX_ARRAY_SIZE], const unsigned size)
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << matrix[i][i] << ", ";
    }
    std::cout << "Main Diagonal has successfully been printed!" << std::endl;
}

void printSecDiagonal(const int matrix[][MAX_ARRAY_SIZE], const unsigned size)
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << matrix[i][size - 1 - i] << ", ";
    }
    std::cout << "Secondary Diagonal has successfully been printed!" << std::endl;
}

int findMaxElement(int matrix[][MAX_ARRAY_SIZE], const unsigned size)
{
    int max = matrix[0][0];
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (matrix[i][j] > max)
                max = matrix[i][j];
        }
    }
    return max;
}

int findMinElement(int matrix[][MAX_ARRAY_SIZE], const unsigned size)
{
    int min = matrix[0][0];
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (matrix[i][j] < min)
                min = matrix[i][j];
        }
    }
    return min;
}

int main()
{
    unsigned size;
    std::cout << "Please enter number of rows and cols : " << std::endl;
    std::cin >> size;

    if (size > MAX_ARRAY_SIZE)
    {
        std::cout << "Incrrect dimensions of matrix" << std::endl;
        return 1;
    }
    int matrix[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];
    innitMatrix(matrix, size);
    printMainDiagonal(matrix, size);
    printSecDiagonal(matrix, size);

    std::cout << "Min element in the matrix is = " << findMinElement(matrix, size) << std::endl;
    std::cout << "Max element in the matrix is = " << findMaxElement(matrix, size) << std::endl;

    return 0;
}