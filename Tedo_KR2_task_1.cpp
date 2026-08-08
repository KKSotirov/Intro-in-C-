#include <iostream>
// RLE
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
    delete[] dest;
    dest = new char[strlen(src) + 1];
    unsigned pos = 0;
    while (*src)
    {
        dest[pos] = *src;
        pos++;
        src++;
    }
    dest[pos] = '\0';
}

int countConsecutive(const char *str)
{
    char seekedSymbol = *str;
    unsigned count = 0;
    while (*str == seekedSymbol)
    {
        count++;
        std::cout << "WOW, we found the symbol : " << seekedSymbol << "  for the " << count << "-th time!" << std::endl;

        str++;
    }
    return count;
}

bool isLetter(const char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

char intToChar(const int number)
{
    return number + '0';
}

void myStrCpopy(char *&dest, const char *src, const unsigned len)
{
    for (size_t i = 0; i < len; i++)
    {
        if (src[i] >= '0' && src[i] <= '9')
        {
            dest[i] = intToChar(src[i]);
        }
        dest[i] = src[i];
    }
    dest[len] = '\0';
}

char *compressString(const char *str)
{
    unsigned len = strlen(str);
    char *helperContainer = new char[len * 2 + 1];
    unsigned newLen = 0;
    while (*str)
    {
        if (!isLetter(*str)) // invalid string!
            return nullptr;

        *helperContainer = *str;
        helperContainer++;
        newLen++;
        int countConsecutiv = countConsecutive(str);
        std::cout << "This is the fucking count Consecutiv value :   " << countConsecutiv << std::endl;
        *helperContainer = intToChar(countConsecutiv);
        helperContainer++;
        newLen++;
        str += countConsecutiv;
    }
    *helperContainer = '\0';
    helperContainer -= newLen;
    char *newStr = new char[newLen + 1];
    myStrCpopy(newStr, helperContainer, newLen);
    delete[] helperContainer;
    str -= newLen;
    delete[] str;
    return newStr;
}

void printStr(const char *str)
{
    unsigned len = strlen(str);
    for (size_t i = 0; i < len; i++)
    {
        std::cout << str[i];
    }

    std::cout << std::endl;
}

int main()
{
    const char *testStr = "KKKyysssS";
    char *amenStr = nullptr;
    strcpy(amenStr, testStr);
    char *theChosenOne = compressString(amenStr);
    std::cout << "The chosen one is :   " << std::endl;
    printStr(theChosenOne);
    delete[] theChosenOne;
    return 0;
}