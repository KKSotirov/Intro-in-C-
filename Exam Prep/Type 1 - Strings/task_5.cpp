#include <iostream>

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
    unsigned len = strlen(src);
    dest = new char[len + 1];
    for (size_t i = 0; i < len; i++)
    {
        dest[i] = src[i];
    }
    dest[len] = '\0';
}

void printStr(const char *str)
{
    while (*str)
    {
        std::cout << *str;
        str++;
    }
}

char *compressString(const char *str)
{
    unsigned len = strlen(str);
    const char *ptr = str;
    char curr = '\0';
    unsigned newLen = 0;
    char *helperContainer = new char[len + 1];
    while (*ptr)
    {
        if (*ptr != curr)
        {
            curr = *ptr;
            *helperContainer = *ptr;
            helperContainer++;
            newLen++;
            ptr++;
        }
        else
            ptr++;
    }
    helperContainer -= newLen; // shifting back the pointer of the helper container
    // now newLen has the size of the new string
    char *compressedStr = new char[newLen + 1];
    for (size_t i = 0; i < newLen; i++)
    {
        compressedStr[i] = helperContainer[i];
    }
    compressedStr[newLen] = '\0';
    delete[] helperContainer;
    return compressedStr;
}

int main()
{
    const char *testStr1 = "dsaadlkkkkkkkkkkkkkkk";
    char *amenStr = nullptr;
    strcpy(amenStr, testStr1);
    char *compressedStr = compressString(amenStr);
    printStr(compressedStr);

    delete[] compressedStr;
    return 0;
}