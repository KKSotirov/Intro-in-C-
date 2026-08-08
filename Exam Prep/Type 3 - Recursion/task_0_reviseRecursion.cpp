#include <iostream>

unsigned countChar(const char *str, const char ch)
{
    if (*str)
        return 0;
    if (*str == ch)
        return 1 + countChar((str + 1), ch);
}

int pow(int number, int degree)
{
    int result = number;
    while (degree > 0)
    {
        result = result * number;
        degree--;
    }
}

void printBoolVectorNHelper(const unsigned N, unsigned currentLen, char *currentVector)
{
    if (currentLen == N)
    {
        // end
        currentVector[currentLen] = '\0';
        currentVector -= currentLen;
        std::cout << "Printing vector: " << currentVector << std::endl;
        return;
    }
    // for every pos - we have two choices : 1 or 0
    *currentVector = '1';
    printBoolVectorNHelper(N, currentLen + 1, currentVector + 1);
    *currentVector = '0';
    printBoolVectorNHelper(N, currentLen + 1, currentVector + 1);
}

void printBoolVectorN(const unsigned N)
{
    char *currentVector = new char[N + 1];
    printBoolVectorNHelper(N, 0, currentVector);
    delete[] currentVector;
}

void generateCombinationsHelper(const unsigned capN, const unsigned lenK, int *currentNumber, int currentLen, int counterFrom1ToN)
{
    if (currentLen == lenK)
    {
        // the end
        for (size_t i = 0; i < currentLen; i++)
        {
            std::cout << currentNumber[i] << " ";
        }
        std::cout << std::endl;
    }

    if (counterFrom1ToN > capN)
    {
        return;
    }

    // for EVERY number from 1 to N, we have TWO choices: 1. INCLUDE, 2. EXCLUDE
    // CHOICE 1: we increment counter, we do not copy it to number
    generateCombinationsHelper(capN, lenK, currentNumber, currentLen, counterFrom1ToN + 1);
    // CHOICE 2:
    *currentNumber = counterFrom1ToN;
    generateCombinationsHelper(capN, lenK, currentNumber + 1, currentLen + 1, counterFrom1ToN + 1);
}

void generateCombinations(const unsigned N, const unsigned K)
{
    // K <= N
    // prints all combinations with K elements      2 1 = 1 2
    int *currentNumber = new int[K + 1];
    generateCombinationsHelper(N, K, currentNumber, 0, 1);
    delete[] currentNumber;
}

int main()
{

    return 0;
}