#include <iostream>
const size_t DIMENSIONS = 4;
const size_t DIMENSIONS_SUBMATRIX = DIMENSIONS / 2;

void innitMatrix(int matrix[][DIMENSIONS], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
}

bool isCorrectElement(int elem)
{
    return elem > 0 && elem < 10;
}

bool isCorrectMatrix(int matrix[][DIMENSIONS])
{
    for (size_t i = 0; i < DIMENSIONS; i++)
    {
        for (size_t j = 0; j < DIMENSIONS; j++)
        {
            if (isCorrectElement(matrix[i][j]) == false)
                return false;
        }
    }
    return true;
}

int checkRowSums(int matrix[][DIMENSIONS])
{
    unsigned currRowSum = 0;
    unsigned firstRowSum = 0;
    for (size_t i = 0; i < DIMENSIONS; i++)
    {
        for (size_t j = 0; j < DIMENSIONS; j++)
        {
            currRowSum += matrix[i][j];
        }
        // here we have finally exited our inbedded for cycle
        // this means that we have successfully added every element from our i-th row to currRowSum
        // if i=0, this means that we have counted the sum of our first row, so we start checking every next row with it
        if (i == 0)
            firstRowSum = currRowSum;
        // here we set the currRowSum counter to 0, which allows it to start counting from the secon row onward
        if (firstRowSum != currRowSum)
            return 0;
        currRowSum = 0;
    }
    return firstRowSum;
}

int checkColSums(int matrix[][DIMENSIONS])
{
    unsigned currColSum = 0;
    unsigned firstColSum = 0;
    for (size_t i = 0; i < DIMENSIONS; i++)
    {
        for (size_t j = 0; j < DIMENSIONS; j++)
        {
            currColSum += matrix[j][i];
        }

        if (i == 0)
            firstColSum = currColSum;
        if (firstColSum != currColSum)
            return 0;
        currColSum = 0;
    }

    return firstColSum;
}

int calcCurrentSubMatrix(int currMatrix[][DIMENSIONS], const size_t currRow, const size_t currCol)
{
    int currSubMatrixSum = 0;
    for (size_t i = currRow; i < currRow + DIMENSIONS_SUBMATRIX; i++)
    {
        for (size_t j = currCol; j < currCol + DIMENSIONS_SUBMATRIX; j++)
        {
            currSubMatrixSum += currMatrix[i][j];
        }
    }
    return currSubMatrixSum;
}

int checkSubMatrixSums(int matrix[][DIMENSIONS])
{
    unsigned currSubMatrixSum = 0;
    unsigned firstSubMatrixSum = calcCurrentSubMatrix(matrix, 0, 0);
    for (size_t i = 0; i < DIMENSIONS; i += DIMENSIONS_SUBMATRIX)
    {
        for (size_t j = 0; j < DIMENSIONS; j += DIMENSIONS_SUBMATRIX)
        {
            currSubMatrixSum = calcCurrentSubMatrix(matrix, i, j);
            if (currSubMatrixSum != firstSubMatrixSum)
                return 0;
        }
    }
    return firstSubMatrixSum;
}

int main()
{
    int matrix[DIMENSIONS][DIMENSIONS];
    innitMatrix(matrix, DIMENSIONS);
    if (isCorrectMatrix(matrix) == false)
        std::cout << "INCORRECT INPUT" << std::endl; // no exceptions learned yet
    else
    {
        // we are working with correct input data, we check every combination individually and then comapare rows with cols with submatrixes
        if (checkRowSums(matrix) == 0 || checkColSums(matrix) == 0 || checkSubMatrixSums(matrix) == 0)
        {
            std::cout << "0          :) " << std::endl;
        }
        else if (checkRowSums(matrix) == checkColSums(matrix) && checkRowSums(matrix) == checkSubMatrixSums(matrix))
        {
            std::cout << "1       Evalata bate, golem si" << std::endl;
        }
        else
            std::cout << "0          :(" << std::endl;
    }
    return 0;
}