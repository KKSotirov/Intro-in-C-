#include <iostream>
// Напишете функция, която приема символен низ и връща нов низ, за който е заделено точно количество памет, съдържащ само онези символи от подадения низ, които се срещат само веднъж в него (запазвайки оригиналния им ред на поява).
unsigned strlen(const char *str)
{
    unsigned len = 0;
    while (*str)
    {
        len++;
        str++;
    }
    return len;
}

void strcopy(char *&dest, const char *src)
{
    if (!src)
        return;
    // delete dest;
    // dest = new char[strlen(src) + 1];
    unsigned len = strlen(src);
    char *temp = new char[len + 1];
    while (*src)
    {
        *temp = *src;
        temp++;
        src++;
    }
    *temp = '\0';
    delete[] dest;
    dest = temp - len;
}

void resize(char *&str)
{
    char *temp = new char[strlen(str) * 2];
    strcopy(temp, str);
    delete[] str;
    str = temp;
}

void setDefaultValues(char *&str)
{
    unsigned len = strlen(str);
    for (size_t i = 0; i < len; i++)
    {
        str[i] = '\0';
    }
}

char *returnUnique(const char *str)
{
    unsigned len = strlen(str);
    unsigned capacity = 2;
    unsigned count = 0;
    char *helper = new char[capacity];
    setDefaultValues(helper);
    int countOccurances[len + 1] = {0};
    for (size_t i = 0; i < len; i++)
    {
        for (size_t j = 0; j < len; j++)
        {
            if (count >= capacity)
                resize(helper);
            if (str[i] != helper[j] && helper[j] == 'NULL')
            {
                helper[j] = str[i];
                countOccurances[j]++;
                count++;
                break; // so we do not fill the whole helper array with the same char
            }
            if (str[i] == helper[j])
            {
                count++;
                countOccurances[j]++;
                break;
            }
        }
    }

    // We now have 1 array with every char once, and we have another array keeping how many times each char has been found
    size_t newSize = 0;
    for (size_t i = 0; i < count; i++)
    {
        if (countOccurances[i] == 1)
            newSize++;
    }

    char *uniqueStr = new char[newSize + 1];
    int pos = 0;
    for (size_t i = 0; i < count; i++)
    {
        if (countOccurances[i] == 1)
        {
            uniqueStr[pos] = helper[i];
        }
    }
    delete[] helper;
    return uniqueStr;
}

void printMatrix(const char *str)
{
    while (*str)
    {
        std::cout << *str;
        str++;
    }
    std::cout << std::endl;
}

int main()
{
    std::cout << "Iskam da se samoubiq" << std::endl;
    const char *testStr = "JokereIAzSumLud!";
    char *str = nullptr;
    strcopy(str, testStr);
    char *amenStr = returnUnique(str);
    printMatrix(amenStr);
}