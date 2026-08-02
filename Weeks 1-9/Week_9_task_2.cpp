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

void addMatrixes(int matrix1[][MAX_MATRIX_SIZE], int matrix2[][MAX_MATRIX_SIZE], int resultMatrix[][MAX_MATRIX_SIZE], const unsigned size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrixes(int matrix1[][MAX_MATRIX_SIZE], int matrix2[][MAX_MATRIX_SIZE], int resultMatrix[][MAX_MATRIX_SIZE], const unsigned size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            resultMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
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
    std::cout << "Please enter matrixes dimensions: " << std::endl;
    std::cin >> size;

    int matrix1[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
    innitMatrix(matrix1, size);
    int matrix2[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
    innitMatrix(matrix2, size);
    int subtractedMatrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
    int addedMatrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];

    addMatrixes(matrix1, matrix2, addedMatrix, size);
    subtractMatrixes(matrix1, matrix2, subtractedMatrix, size);
    std::cout << "Printing added matrix: " << std::endl;
    printMatrix(addedMatrix, size);
    std::cout << "Printing subtracted matrix: " << std::endl;
    printMatrix(subtractedMatrix, size);

    return 0;
}