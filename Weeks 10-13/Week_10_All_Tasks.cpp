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
    // if A is smaller as ASCII value, we subtract on row 101, so it works fine regardless
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

    char *src = str + size - 1; // sets the pointer of the original string at the end
    char *dest = temp;          // helps us not move the temp pointer

    // filling temp backwards
    while (src >= str)
    {
        *dest = *src;
        dest++;
        src--;
    }
    *dest = '\0'; // !

    src = str;
    dest = temp;
    while (*dest)
    {
        *src = *dest;
        src++;
        dest++;
    }

    delete[] temp; // Чистим оригиналния указател на temp без никакво изместване!
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
    copyPtr = nullptr;
    reversedPtr = nullptr;
    return true;
}

bool isLetter(const char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

char *mostUsedWord(char *&str)
{
    unsigned size = strlen(str);
    int timesEachWordFound[countWords(str) + 1] = {0};
    // 1 pass -> count every word
    // 2 pass -> get the most frequent one
    char *ptrCopy = str;
    char *tempWordHolder = new char[size + 1];
    for (size_t i = 0; i < size; i++)
    {
        if (isLetter(ptrCopy[i]))
        {
            // first compare if word had already been copied, then if not -> copy it
            for (size_t j = 0; j < size; j++)
            {
                while (ptrCopy[j] == *tempWordHolder)
                    ... // тук искам да направя проверка дали думата вече е била копирана в контейнера ни с отделни думи, ако вече я има там, то тя значи се среща повторно, някак си намирам индекса на тази дума и добавям в масива с брой срещания +1
            }

            while (isLetter(ptrCopy[i]))
            {
                *tempWordHolder = ptrCopy[i];
                i++;
            }
        }
    }
}

int main()
{
    // std::cout << "Please enter array: " << std::endl;
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