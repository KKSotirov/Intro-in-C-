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

bool isLowerLetter(const char ch)
{
    return ch >= 'a' && ch <= 'z';
}

bool isCapLetter(const char ch)
{
    return ch >= 'A' && ch <= 'Z';
}

void toCapLetters(char *&str)
{
    unsigned size = strlen(str);
    int asciiDist = 'a' - 'A';
    for (size_t i = 0; i < size; i++)
    {
        if (isLowerLetter(str[i]))
            str[i] -= asciiDist;
    }
}

void toLowerLetters(char *&str)
{
    unsigned size = strlen(str);
    int asciiDist = 'a' - 'A';
    for (size_t i = 0; i < size; i++)
    {
        if (isCapLetter(str[i]))
            str[i] += asciiDist;
    }
}

void removeSpaces(char *&str)
{
    unsigned size = strlen(str);
    for (size_t i = 0; i < size; i++)
    {
        if (str[i] == ' ')
            str[i] = '_';
    }
}

void printMatrix(char *str)
{
    while (*str)
    {
        std::cout << *str;
        str++;
    }
    std::cout << std::endl;
}

void free(char *&str)
{
    delete[] str;
}

unsigned countWords(char *&str)
{
    unsigned size = strlen(str);
    unsigned wordsCount = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (isLowerLetter(str[i]) || isCapLetter(str[i]))
        {
            while (isLowerLetter(str[i]) || isCapLetter(str[i]))
            {
                i++;
            }
            wordsCount++;
        }
    }
    return wordsCount;
}

void flipStr(char *&str)
{
    if (!str)
        return;

    unsigned size = strlen(str);
    char *temp = new char[size + 1];

    char *src = str + size - 1;
    char *dest = temp;

    while (src >= str)
    {
        *dest = *src;
        dest++;
        src--;
    }
    *dest = '\0';

    src = str;
    dest = temp;
    while (*dest)
    {
        *src = *dest;
        src++;
        dest++;
    }

    delete[] temp;
}

bool isPalindrome(char *&str)
{
    unsigned size = strlen(str);
    char *reversedPtr = str + size - 1;
    char *copyPtr = str;
    unsigned half = size / 2;

    for (size_t i = 0; i < half; i++)
    {
        if (*copyPtr != *reversedPtr)
            return false;
        else
        {
            copyPtr++;
            reversedPtr--;
        }
    }

    // Премахнати са delete copyPtr; и delete reversedPtr; (причиняваха crash)
    return true;
}

bool isLetter(const char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// Помощна функция: Сравнява две думи по диапазони [start, end)
bool areWordsEqual(const char *s1, const char *e1, const char *s2, const char *e2)
{
    if ((e1 - s1) != (e2 - s2))
        return false;

    while (s1 < e1)
    {
        char c1 = (*s1 >= 'A' && *s1 <= 'Z') ? (*s1 + ('a' - 'A')) : *s1;
        char c2 = (*s2 >= 'A' && *s2 <= 'Z') ? (*s2 + ('a' - 'A')) : *s2;

        if (c1 != c2)
            return false;

        s1++;
        s2++;
    }
    return true;
}

// Помощна функция: Извлича следващата дума [start, end)
bool getNextWord(const char *&ptr, const char *&start, const char *&end)
{
    while (*ptr && !isLetter(*ptr))
        ptr++;

    if (!*ptr)
        return false;

    start = ptr;
    while (*ptr && isLetter(*ptr))
        ptr++;

    end = ptr;
    return true;
}

char *mostUsedWord(char *&str)
{
    if (!str || *str == '\0')
        return nullptr;

    const char *bestStart = nullptr;
    const char *bestEnd = nullptr;
    int maxCount = 0;

    const char *ptr1 = str;
    const char *start1 = nullptr;
    const char *end1 = nullptr;

    while (getNextWord(ptr1, start1, end1))
    {
        int currentCount = 0;
        const char *ptr2 = str;
        const char *start2 = nullptr;
        const char *end2 = nullptr;

        while (getNextWord(ptr2, start2, end2))
        {
            if (areWordsEqual(start1, end1, start2, end2))
            {
                currentCount++;
            }
        }

        if (currentCount > maxCount)
        {
            maxCount = currentCount;
            bestStart = start1;
            bestEnd = end1;
        }
    }

    if (!bestStart || !bestEnd)
        return nullptr;

    size_t len = bestEnd - bestStart;
    char *result = new char[len + 1];

    for (size_t i = 0; i < len; i++)
    {
        result[i] = bestStart[i];
    }
    result[len] = '\0';

    return result;
}

int main()
{
    const char *sourceText1 = "There is no war in Ba Sing Se";
    const char *sourceText2 = ", and there is no inflation since adopting the Euro";
    char *testString = nullptr;

    strcpy(testString, sourceText1);
    removeSpaces(testString);
    toCapLetters(testString);
    printMatrix(testString);

    strcat(sourceText1, sourceText2, testString);
    printMatrix(testString);
    std::cout << "Word count = " << countWords(testString) << std::endl;

    // Намиране и отпечатване на най-честата дума
    char *mostUsed = mostUsedWord(testString);
    if (mostUsed)
    {
        std::cout << "Most used word: " << mostUsed << std::endl;
        delete[] mostUsed;
    }

    const char *palindomeText = "ABCBA";
    strcpy(testString, palindomeText);
    if (isPalindrome(testString))
        std::cout << "Yes, the string: [" << testString << "]  is a palindrome!" << std::endl;
    else
        std::cout << "No, the string: [" << testString << "]  is not a palindrome!" << std::endl;

    std::cout << "Word count = " << countWords(testString) << std::endl;
    free(testString);

    return 0;
}