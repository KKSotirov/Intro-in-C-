#include <iostream>

int strlen(const char *str)
{
    int size = 0;
    while (*str)
    {
        size++;
        str++;
    }
    return size;
}

void strcpy(char *&dest, const char *&src)
{
    delete[] dest;
    dest = new char[strlen(src) + 1];
    for (size_t i = 0; i < strlen(src); i++)
    {
        dest[i] = src[i];
    }
    dest[strlen(src)] = '\0';
}

void strcat(const char *str1, const char *str2, char *&resultArray)
{
    delete[] resultArray;
    resultArray = new char[strlen(str1) + strlen(str2) + 1];
    for (size_t i = 0; i < strlen(str1); i++)
    {
        resultArray[i] = str1[i];
    }
    for (size_t j = 0; j < strlen(str2); j++)
    {
        resultArray[j + strlen(str1)] = str2[j];
    }
    resultArray[strlen(str1) + strlen(str2)] = '\0';
}

int strcmp(const char *str1, const char *str2)
{
    unsigned size = strlen(str1) > strlen(str2) ? strlen(str2) : strlen(str1);
    int cmpValue = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (str1[i] > str2[i])
        {
            cmpValue = 1;
            std::cout << "The first string is bigger" << std::endl;
            return cmpValue;
        }
        else if (str1[i] < str2[i])
        {
            cmpValue = -1;
            std::cout << "The second string is bigger" << std::endl;
            return cmpValue;
        }
    }
    return cmpValue;
}

int pow(int num, const int degree)
{
    int result = 1;
    for (size_t i = 0; i < degree; i++)
    {
        result *= num;
    }
    return result;
}

int parseToInt(const char *str)
{
    int intValue = 0;
    unsigned helper = 10;
    for (size_t i = strlen(str); i > 0; i--)
    {
        intValue = intValue + pow(10, i - 1) * (str[strlen(str) - i] - '0');
    }
    return intValue;
}

int main()
{
    std::cout << "Please enter array: " << std::endl;

    return 0;
}