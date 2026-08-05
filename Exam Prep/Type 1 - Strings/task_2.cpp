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
    dest = new char[strlen(src) + 1];
    for (size_t i = 0; i < strlen(src); i++)
    {
        dest[i] = src[i];
    }
    dest[strlen(src)] = '\0';
}

bool isNum(const char ch)
{
    return ch >= '0' && ch <= '9';
}

int pow(const int num, int degree)
{
    int result = 1;
    while (degree > 0)
    {
        result = result * num;
        degree--;
    }
    return result;
}

int charToInt(const char ch)
{
    // return static_cast<int>(ch);
    return ch - '0';
}

int calculateSum(const char *str)
{
    unsigned totalSum = 0;
    bool foundAny = false;
    unsigned currNumber;
    const char *ptr = str;
    while (*ptr)
    {
        if (isNum(*ptr))
        {
            foundAny = true;
            currNumber = 0;
            while (isNum(*ptr))
            {
                currNumber = currNumber * 10 + charToInt(*ptr);
                ptr++;
            }
            totalSum += currNumber;
        }
        else
            ptr++;
    }
    if (foundAny == false)
        return -1;
    return totalSum;
}

int main()
{
    std::cout << "Send Help 0_0" << std::endl;
    const char *testStr1 = "5J3o5kere17IAzSumLud!173";
    const char *testStr2 = "JokereIAzSumLud!";
    char *str = nullptr;
    strcpy(str, testStr1);
    int sum = calculateSum(str);
    if (sum == -1)
    {
        std::cout << "There are no numbers in the string!!!" << std::endl;
        return 0;
    }
    std::cout << "The sum is: " << sum;
    delete[] str;
}