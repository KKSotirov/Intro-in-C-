#include <iostream>

unsigned countChar(const char *str, const char ch)
{
    if (*str)
        return 0;
    if (*str == ch)
        return 1 + countChar((str + 1), ch);
}

int main()
{

    return 0;
}