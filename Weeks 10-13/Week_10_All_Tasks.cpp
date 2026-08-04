#include <iostream>

int strlen(const char *str)
{
    int size = 0;
    while (*str)
    {
        size++;
    }
    return size;
}

void strcpy(char *dest, const char *src)
{
    delete[] dest;
    dest = new char[strlen(src) + 1];
    for (size_t i = 0; i < strlen(src); i++)
    {
        dest[i] = src[i];
    }
}

void strcat(const char *str1, const char *str2, char *resultArray)
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
}

int strcmp(const char *str1, const char *str2)
{
    unsigned size = strlen(str1) > strlen(str2) ? strlen(str1) : strlen(str2);
    int cmpValue = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (str1[i] - NULL > str2[i] - NULL)
        {
            cmpValue = 1;
            std::cout << "The first string is bigger" << std::endl;
        }
        else if (str1[i] - NULL < str2[i] - NULL)
        {
            cmpValue = -1;
            std::cout << "The second string is bigger" << std::endl;
        }
    }
    return cmpValue;
}

int pow(int num, const int degree)
{
    for (size_t i = 0; i < degree; i++)
    {
        num = num * num;
    }
    return num;
}

int parseToInt(const char *str)
{
    int intValue;
    unsigned helper = 10;
    for (size_t i = strlen(str); i > 0; i--)
    {
        intValue = intValue + pow(10, i - 1) * (str[strlen(str) - i] - '0');
    }
    return intValue;
}

int main()
{

    return 0;
}