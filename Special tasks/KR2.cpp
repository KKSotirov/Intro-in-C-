#include <iostream>
const size_t MAX_ARR_SIZE = 1000;

void initStr(char *str)
{
    char ch;
    while (std::cin.get(ch) && ch != '\n')
    {
        *str = ch;
        str++;
    }
    *str = '\0';
}

size_t strLen(char *str)
{
    size_t len = 0;
    while (*str)
    {
        len++;
        str++;
    }
    return len;
}

bool isValid(char *str, int count)
{
    if (*str == '\0')
    {
        if (count == 0)
            return true;
        else
            return false;
    }
    if (*str == '(')
        count++;
    if (*str == ')')
        count--;
    if (count < 0)
        return false;
    return isValid(str + 1, count);
}
int main()
{
    //     Даден е низ, съставен само от символите '(' и ')'. Низът е с дължина до 1000. Да се напише
    // рекурсивна функция, която проверява дали скобите в низа са правилно вложени.
    // Един низ е правилен, ако:
    // • всеки отворен '(' има съответстваща затворена ')'
    // • никога не се срещат повече затворени скоби от отворени при обхождане отляво надясно.
    // Може да използвате std::boolalpha

    // Пример 1:
    // Вход: (()())
    // Изход : True
    char *str = new char[MAX_ARR_SIZE];
    std::cout << "Please enter string. " << std::endl;
    initStr(str);
    int count = 0;
    std::cout << "The entered string is correct : " << std::boolalpha << isValid(str, count);

    delete[] str;
    return 0;
}