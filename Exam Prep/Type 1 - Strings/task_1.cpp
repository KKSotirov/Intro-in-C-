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

void strcpy(char *&dest, const char *src)
{
    if (!src)
        return;
    delete[] dest;
    dest = new char[strlen(src) + 1];
    for (size_t i = 0; i < strlen(src); i++)
    {
        dest[i] = src[i];
    }
    dest[strlen(src)] = '\0';
}

void resize(char *&str, unsigned &capacity)
{
    char *temp = new char[capacity * 2];
    strcpy(temp, str);
    capacity *= 2;
    delete[] str;
    str = temp;
}

int charToInt(const char ch)
{
    return static_cast<int>(ch);
}
char *returnUnique(const char *str)
{
    if (!str)
        return nullptr;
    int countOccurances[256] = {0};
    const char *ptr = str;
    while (*ptr)
    {
        countOccurances[charToInt(*ptr)]++;
        ptr++;
    }

    unsigned size = 0;
    ptr = str;
    while (*ptr)
    {
        if (countOccurances[charToInt(*ptr)] == 1)
            size++;
        ptr++;
    }
    char *uniqueStr = new char[size + 1];
    unsigned pos = 0;
    ptr = str;
    while (*ptr)
    {
        if (countOccurances[charToInt(*ptr)] == 1)
        {
            uniqueStr[pos] = *ptr;
            pos++;
        }
        ptr++;
    }
    uniqueStr[pos] = '\0';
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
    std::cout << "Send Help 0_0" << std::endl;
    const char *testStr = "JokereIAzSumLud!";
    char *str = nullptr;
    strcpy(str, testStr);
    char *amenStr = returnUnique(str);
    printMatrix(amenStr);

    delete[] str;
}