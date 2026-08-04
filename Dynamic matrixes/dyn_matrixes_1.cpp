#include <iostream>
int **createMatrix(const unsigned rows, const unsigned cols)
{
    int **matrix = new int *[cols];
    for (size_t i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
    }
    return matrix;
}

void innitMatrix(int **matrix, const unsigned rows, const unsigned cols)
{
    std::cout << "Please enter parameters of " << rows << "x" << cols << " matrix!" << std::endl;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
}

void printMatrix(const int **matrix, const unsigned rows, const unsigned cols)
{
    std::cout << "Printing matrix: " << std::endl;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void free(int **&matrix, const unsigned rows, const unsigned cols)
{
    if (!matrix)
        return;
    for (size_t i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
}

int main()
{
    unsigned rows, cols;
    std::cout << "Please enter number of rows for matrix" << std::endl;
    std::cin >> rows;
    std::cout << "Please enter number of cols for matrix" << std::endl;
    std::cin >> cols;
}