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

void printStr(const char *str)
{
    while (*str)
    {
        std::cout << *str;
        str++;
    }
    std::cout << std::endl;
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
char ignoreAllCaps(char ch)
{
    if (isLetter(ch))
    {
        if (isCapital(ch))
            toLowerCase(ch);
    }
    return ch;
}

void setToFirstWord(char *&dest, const char *src)
{
    unsigned len = 0;
    while (*src)
    {
        if (isLetter(*src))
        {
            while (*src && isLetter(*src))
            {
                *dest = *src;
                dest++;
                src++;
                len++;
            }
            break;
        }
        else
        {
            src++;
        }
    }
    *dest = '\0';
    dest -= len; // bringing the pointer back to origin
}

bool notSameWord(char *last, const char *curr)
{
    unsigned len = strlen(last);
    while (*last)
    {
        if (ignoreAllCaps(*last) != *curr)
            return true;
        else
        {
            last++;
            curr++;
        }
    }
    if (*last != '\0' || isLetter(*curr))
        return true;
    return false;
}

unsigned deleteConsecutiveAndCountWords(char *&str)
{
    unsigned len = strlen(str);
    const char *ptr = str;
    char *helperContainer = new char[len + 1];
    unsigned newLen = 0;
    unsigned countWords = 1;

    char *lastWord = new char[len + 1];
    setToFirstWord(lastWord, ptr);
    unsigned lastWordLen = strlen(lastWord);

    // Writing the first word in helper container
    for (unsigned i = 0; i < lastWordLen; i++)
    {
        *helperContainer = lastWord[i];
        helperContainer++;
        newLen++;
    }

    // Skipping first word (we have already written it in helper container)
    while (*ptr && !isLetter(*ptr))
        ptr++;
    while (*ptr && isLetter(*ptr))
        ptr++;

    // the real deal
    while (*ptr)
    {
        if (isLetter(*ptr))
        {
            if (notSameWord(lastWord, ptr))
            {
                countWords++;
                const char *wordStart = ptr;
                unsigned wordLen = 0;
                while (*ptr && isLetter(*ptr))
                {
                    wordLen++;
                    ptr++;
                }

                // using for cycles in order not to move pointers
                const char *tempWord = wordStart;
                for (unsigned i = 0; i < wordLen; i++)
                {
                    lastWord[i] = tempWord[i];
                }
                lastWord[wordLen] = '\0';
                lastWordLen = wordLen;

                // New word --> to helper container it goes
                tempWord = wordStart;
                for (unsigned i = 0; i < wordLen; i++)
                {
                    *helperContainer = *tempWord;
                    helperContainer++;
                    newLen++;
                    tempWord++;
                }
            }
            else
            {
                // duplicate, we skip it
                // Тъй като интервалът преди тази дублирана дума вече е записан в буфера,
                // го изтриваме, като върнем контейнера с една позиция назад!
                helperContainer--;
                newLen--;

                while (*ptr && isLetter(*ptr))
                {
                    ptr++;
                }
            }
        }
        else
        {
            // current symbol is not a letter, so we keep it in helperContainer
            *helperContainer = *ptr;
            helperContainer++;
            newLen++;
            ptr++;
        }
    }
    *helperContainer = '\0';
    helperContainer -= newLen;
    char *newStr = new char[newLen + 1];
    myStrCopy(newStr, helperContainer, newLen);

    delete[] lastWord;
    delete[] helperContainer;
    delete[] str;
    str = newStr;

    return countWords;
}

void printWord(char *str)
{
    while (*str && isLetter(*str))
    {
        std::cout << *str;
        str++;
    }
    std::cout << std::endl;
}

char *normalizeStr(char *&originalStr)
{
    removeEdgeIntervals(originalStr);
    compressIntervals(originalStr);
    cutConsecutivePunctuationMarks(originalStr);
    transformIntoSentences(originalStr);
    unsigned countWords = deleteConsecutiveAndCountWords(originalStr);
    // length of longest word
    // return char* to the beginning of the longest word
    char *originalStrCpy = originalStr;
    unsigned maxWordLen = 0;
    unsigned currWordLen = 0;
    char *startPosOfLongestWord = nullptr;
    while (*originalStrCpy)
    {
        if (isLetter(*originalStrCpy))
        {
            currWordLen = 0; // for every new word, we set its length starting from 0
            while (*originalStrCpy && isLetter(*originalStrCpy))
            {
                currWordLen++;
                originalStrCpy++;
            }
            if (currWordLen > maxWordLen)
            {
                maxWordLen = currWordLen;
                startPosOfLongestWord = (originalStrCpy - currWordLen);
            }
        }
        else
        {
            originalStrCpy++;
        }
    }
    // at the end of this while we have:  length of the longest word, and its starting adress

    // PRINT NORMALIZED
    printStr(originalStr);
    std::cout << "Number of words in normalized String is = " << countWords << std::endl;
    std::cout << "The length of the longest word is = " << maxWordLen << std::endl;
    std::cout << "The longest word is = ";
    printWord(startPosOfLongestWord);

    return startPosOfLongestWord;
}

int main()
{
    std::cout << "Send Help 0_0" << std::endl;
    const char *testStr = "JoKerE   Jokere  pomosht! imam ImAm nuzhdA oT     ot, poMo6T!!?!???.";
    char *str = nullptr;
    strcpy(str, testStr);
    char *normalizedStr = normalizeStr(str);
    std::cout << "Final print " << std::endl;
    printStr(normalizedStr);

    delete[] str;
    return 0;
}