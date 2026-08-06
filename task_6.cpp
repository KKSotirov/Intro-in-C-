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

void myStrCopy(char *&dest, const char *src, const unsigned len)
{
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
    if (!str || !*str)
        return;

    // Skipping the starting intervals
    const char *start = str;
    while (*start && *start == ' ')
    {
        start++;
    }

    if (!*start) // the whole string is only intervals
    {
        delete[] str;
        str = new char[1];
        str[0] = '\0';
        return;
    }

    // Finding the last symbol that is not an interval
    const char *end = str + strlen(str) - 1;
    while (end > start && *end == ' ')
    {
        end--;
    }

    // Calculating newLen and init of newStr
    unsigned newLen = (end - start) + 1;
    char *newStr = new char[newLen + 1];

    for (size_t i = 0; i < newLen; i++)
    {
        newStr[i] = start[i];
    }
    newStr[newLen] = '\0';

    delete[] str;
    str = newStr;
}

void compressIntervals(char *&str)
{
    unsigned len = strlen(str);
    const char *ptr = str;
    char *helperContainer = new char[len + 1];
    unsigned newLen = 0;
    while (*ptr)
    {
        if (*ptr == ' ')
        {
            while (*ptr && *ptr == ' ')
            {
                ptr++;
            }
            *helperContainer = ' ';
            helperContainer++;
            newLen++;
        }
        else
        {
            *helperContainer = *ptr;
            helperContainer++;
            newLen++;
            ptr++;
        }
    }
    helperContainer -= newLen;
    char *newStr = new char[newLen + 1];
    myStrCopy(newStr, helperContainer, newLen);
    delete[] helperContainer;
    delete[] str;
    str = newStr;
}

bool isSentenceEnd(const char ch)
{
    return (ch == '.' || ch == '!' || ch == '?');
}

void cutConsecutivePunctuationMarks(char *&str)
{
    unsigned len = strlen(str);
    const char *ptr = str;
    char *helperContainer = new char[len + 1];
    unsigned newLen = 0;
    while (*ptr)
    {
        if (isSentenceEnd(*ptr))
        {
            while (*ptr && isSentenceEnd(*ptr))
            {
                ptr++;
            }
            *helperContainer = *(ptr - 1); // last consecutive punctuation mark
            helperContainer++;
            newLen++;
        }
        else
        {
            *helperContainer = *ptr;
            ptr++;
            helperContainer++;
            newLen++;
        }
    }
    helperContainer -= newLen;
    char *newStr = new char[newLen + 1];
    myStrCopy(newStr, helperContainer, newLen);
    delete[] helperContainer;
    delete[] str;
    str = newStr;
}

void transformIntoSentences(char *&str)
{
    bool isSentenceStart = true;
    unsigned len = strlen(str);
    char *ptr = str;
    char *helperContainer = new char[len + 1];
    unsigned newLen = 0;
    // this function : 1. transforms letters to capital and lower
    while (*ptr)
    {
        if (isSentenceStart && isLetter(*ptr))
        {
            *helperContainer = *ptr;
            toCapitalCase(*helperContainer);
            helperContainer++;
            isSentenceStart = false;
            newLen++;
        }
        else if (isSentenceEnd(*ptr))
        {
            isSentenceStart = true;
            *helperContainer = *ptr;
            helperContainer++;
            newLen++;
        }

        else if (isSentenceStart == false && isLetter(*ptr))
        {
            *helperContainer = *ptr;
            toLowerCase(*helperContainer);
            helperContainer++;
            newLen++;
        }
        else // here we copy every other type of char, except letters and intervals
        {
            *helperContainer = *ptr;
            helperContainer++;
            newLen++;
        }
        ptr++;
    }
    helperContainer -= newLen;
    char *newStr = new char[newLen + 1];
    myStrCopy(newStr, helperContainer, newLen);
    delete[] helperContainer;
    delete[] str;
    str = newStr;
}

void normalizeStr(char *&originalStr)
{
    removeEdgeIntervals(originalStr);
    compressIntervals(originalStr);
    cutConsecutivePunctuationMarks(originalStr);
    transformIntoSentences(originalStr);
    // final changes
}

int main()
{

    return 0;
}