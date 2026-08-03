#include <iostream>

// Динамично преоразмеряване на масив (увеличаване на капацитета двойно)
void resize(int *&arr, size_t &capacity)
{
    size_t newCapacity = capacity * 2;
    int *newArr = new int[newCapacity];

    for (size_t i = 0; i < capacity; i++)
    {
        newArr[i] = arr[i];
    }

    delete[] arr;
    arr = newArr;
    capacity = newCapacity;
}

// Заделяне на памет за NxN матрица
int **allocateMatrix(const size_t size)
{
    int **matrix = new int *[size];
    for (size_t i = 0; i < size; i++)
    {
        matrix[i] = new int[size];
    }
    return matrix;
}

// Освобождаване на паметта за матрицата
void freeMatrix(int **matrix, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// Проверка за триъгълност спрямо главния диагонал ==> всички елементи под гл. диагонал трябва да са нули
bool isTriangular(const int *const *matrix, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (j < i && matrix[i][j] != 0)
                return false;
        }
    }
    return true;
}

int main()
{
    size_t capacity = 2;
    size_t n = 0;
    int *firstRow = new int[capacity];

    // 1. Прочитаме първия ред динамично без статични буфери
    while (true)
    {
        int num;
        if (!(std::cin >> num))
        {
            break;
        }

        // Ако масивът се напълни, го разширяваме двойно в Хипа
        if (n == capacity)
        {
            resize(firstRow, capacity);
        }
        firstRow[n++] = num;

        // Пропускаме празните места (шпации/табулации)
        while (std::cin.peek() == ' ' || std::cin.peek() == '\t' || std::cin.peek() == '\r')
        {
            std::cin.get();
        }

        // Ако стигнем до Enter ('\n'), първият ред е завършен
        if (std::cin.peek() == '\n' || std::cin.peek() == EOF)
        {
            std::cin.get(); // премахваме '\n' от входния поток
            break;
        }
    }

    if (n == 0)
    {
        delete[] firstRow;
        return 1;
    }

    // 2. Заделяме памет за точния размер NxN
    int **matrix = allocateMatrix(n);

    // 3. Копираме първия ред в матрицата и освобождаваме временния динамичен масив
    for (size_t j = 0; j < n; j++)
    {
        matrix[0][j] = firstRow[j];
    }
    delete[] firstRow;

    // 4. Прочитаме останалите (n - 1) реда директно в матрицата
    for (size_t i = 1; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            std::cin >> matrix[i][j];
        }
    }

    if (isTriangular(matrix, capacity) == true)
        std::cout << "Yes, the matrix is triangular!" << std::endl;
    else
        std::cout << "No, the matrix is not triangular!" << std::endl;

    // 6. Почистване на матрицата от Хипа
    freeMatrix(matrix, n);

    return 0;
}