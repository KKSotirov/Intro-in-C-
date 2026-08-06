#include <iostream>
const size_t DIST_CAPITAL_TO_LOWER = 'a' - 'A';

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
    unsigned len = strlen(src);
    delete[] dest;
    dest = new char[len + 1];
    for (size_t i = 0; i < len; i++)
    {
        dest[i] = src[i];
    }
    dest[len] = '\0';
}

bool isLower(const char ch)
{
    return (ch >= 'a' && ch <= 'z');
}

bool isCapital(const char ch)
{
    return (ch >= 'A' && ch <= 'Z');
}

bool isLetter(const char ch)
{
    return isCapital(ch) || isLower(ch);
}

void toLowerCase(char &ch)
{
    if (isCapital(ch))
        ch += DIST_CAPITAL_TO_LOWER;
    // in the ascii table the capital go first and then come the lower letters
}

void toCapitalCase(char &ch)
{
    if (isLower(ch))
        ch -= DIST_CAPITAL_TO_LOWER;
}

void removeEdgeIntervals(char *&str)
{
    unsigned len = strlen(str);
    const char *ptr = str;
    char *helperContainer = new char[len + 1];
    bool foundLetter = false;
    unsigned newLen = 0;
    while (*ptr)
    {
        if (isLetter(*ptr))
            foundLetter = true;

        if (foundLetter == false)
        {
            while (*ptr == ' ')
                ptr++;
        }
        else
        {
            if (*ptr != ' ')
            {
                *helperContainer = *ptr;
                helperContainer++;
                newLen++;
                ptr++;
            }
        }
    }
    helperContainer -= newLen;
    char *newStr = new char[newLen + 1];
    for (size_t i = 0; i < newLen; i++)
    {
        newStr[i] = helperContainer[i];
    }
    newStr[len] = '\0';
    delete[] helperContainer;
    delete[] str;
    str = newStr;
}

int main()
{

    return 0;
}