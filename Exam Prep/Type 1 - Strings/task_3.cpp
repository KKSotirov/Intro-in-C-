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
    unsigned len = strlen(src);
    delete[] dest;
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
    std::cout << std::endl;
}

char *normalizeStr(const char *str)
{
    if (!str)
        return nullptr;

    bool foundSymbol = false;
    unsigned helperContainerSize = 0;
    const char *ptr = str;

    // Заделяме буфер с максимална възможна дължина
    char *helperContainer = new char[strlen(str) + 1];
    char *origHelper = helperContainer; // Пазим си началния адрес за триене по-късно

    while (*ptr)
    {
        // Ако намерим интервал
        if (*ptr == ' ')
        {
            // Нормализираме интервалите само ако ВЕЧЕ сме срещнали дума (премахва водещите и свива вътрешните)
            if (foundSymbol)
            {
                // Прескачаме всички поредни интервали до следващия символ
                while (*ptr && *ptr == ' ')
                {
                    ptr++;
                }
                // Ако след интервалите все още има символ, записваме само ЕДИН интервал
                if (*ptr)
                {
                    *helperContainer = ' ';
                    helperContainer++;
                    helperContainerSize++;
                }
                continue; // Продължаваме напред в цикъла
            }
            else
            {
                // Ако все още не сме намерили символ, това са водещи интервали -> просто ги прескачаме!
                ptr++;
                continue;
            }
        }
        else
        {
            // Намерили сме истински символ (не е интервал)
            foundSymbol = true;
            *helperContainer = *ptr;
            helperContainer++;
            helperContainerSize++;
            ptr++;
        }
    }

    // Заделяме точното количество памет за резултата
    char *normalizedStr = new char[helperContainerSize + 1];

    // Връщаме указателите в началото, за да прехвърлим данните
    helperContainer = origHelper;

    for (unsigned i = 0; i < helperContainerSize; i++)
    {
        normalizedStr[i] = helperContainer[i];
    }
    normalizedStr[helperContainerSize] = '\0';

    // Чистим помощния буфер, чийто адрес пазим безопасно в origHelper!
    delete[] origHelper;

    return normalizedStr;
}

int main()
{
    std::cout << "Send Help 0_0" << std::endl;
    const char *testStr = "                 Joke     re I  Az     Sum   Lud!     .";
    char *str = nullptr;
    strcpy(str, testStr);
    char *normalizedStr = normalizeStr(str);
    std::cout << "Final print " << std::endl;
    printStr(normalizedStr);

    delete[] normalizedStr;
    return 0;
}