#include <stdlib.h>

struct NumberLine
{
    long lowerBound;
    long upperBound;
};

// Assumes lowerLimit and upperLimit have same number of digits
struct NumberLine* getNumberLine(long lowerLimit, long upperLimit);

int getLengthOfNumber(long number);