#include <iostream>

unsigned strlen(const char *str)
{
    unsigned len = 0;
    while (*str)
    {
        str++;
        len++;
    }
    return len;
}

void strcpy(char *&dest, const char *src)
{
    if (!src)
        return;
    unsigned len = strlen(src);
    delete[] dest;
    dest = new char[len + 1];
    for (size_t i = 0; i < len; i++)
    {
        dest[i] = src[i];
    }
    dest[len] = '\0';
}

char *returnMirrored(const char *str)
{
    const char *ptr = str;
    unsigned len = strlen(str);
    char *mirroredStr = new char[len + 1];
    for (size_t i = 0; i < len; i++)
    {
        mirroredStr[i] = ptr[len - i - 1];
        // 0 1 2 3 4 '\0'              0    5
    }
    mirroredStr[len] = '\0';
    return mirroredStr;
}

void printStr(const char *str)
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
    const char *testStr = "AlucarD";
    char *str = nullptr;
    strcpy(str, testStr);
    char *mirroredStr = returnMirrored(str);
    std::cout << "Final print " << std::endl;
    printStr(mirroredStr);

    return 0;
}