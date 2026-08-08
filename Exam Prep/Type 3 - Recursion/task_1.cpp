// int* str, size_t len, int countKEven, currSum
// calculates the number of : all subsets with K even numbers, and sum is uneven

unsigned countSubSets(const unsigned *str, const unsigned len, unsigned countEvenNumbs, unsigned index, unsigned currSum, const unsigned targetK)
{
    // base of recursion
    if (index == len)
    {
        // we have reached the end of the str
        return (currSum % 2 != 0 && countEvenNumbs == targetK ? 1 : 0);
        // if sum is uneven and there are K number of even numbers in this subset, we return 1, else - 0
    }

    // currently looking at a specific index/number
    // we either include or exclude, first we calclulate if it is an even number
    int nextCountEvenNumbs = countEvenNumbs + (str[index] % 2 == 0 ? 1 : 0);
    // INCLUDE
    unsigned includeCurrentNumber = countSubSets(str, len, nextCountEvenNumbs, index + 1, currSum + str[index], targetK);
    // EXCLUDE
    unsigned excludeCurrentNumber = countSubSets(str, len, countEvenNumbs, index + 1, currSum, targetK);

    return includeCurrentNumber + excludeCurrentNumber;
}