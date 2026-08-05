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
    bool hasNumbs = false;
    int sum = -1;
    unsigned consequtiveNumbers = 0;
    const char *ptr = str;
    while (*ptr)
    {
        while (isNum(*ptr))
        {
            hasNumbs = true;
            std::cout << std::endl;
            consequtiveNumbers++;
            ptr++;
        }
        if (consequtiveNumbers != 0)
        {
            // we have just ended reading a series of numbers
            ptr -= consequtiveNumbers;
            // bring the pointer back and start multiplying
            while (isNum(*ptr))
            {
                sum += charToInt(*ptr) * pow(10, consequtiveNumbers - 1);
                consequtiveNumbers--;
                ptr++;
            }
            consequtiveNumbers = 0;
        }
        ptr++;
    }
    if (hasNumbs)
        sum++;
    return sum;
}

int main()
{
    std::cout << "Send Help 0_0" << std::endl;
    const char *testStr1 = "50J3o50kere17IAzSumLud!1730";
    const char *testStr2 = "JokereIAzSumLud!";
    char *str = nullptr;
    strcpy(str, testStr1);
    if (calculateSum(str) == -1)
    {
        std::cout << "There are no numbers in the string!!!" << std::endl;
        return 0;
    }
    std::cout << "The sum is: " << calculateSum(str);
    delete[] str;
}