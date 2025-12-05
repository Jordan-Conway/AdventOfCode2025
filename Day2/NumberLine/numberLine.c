#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include "numberLine.h"

int getLengthOfNumber(long number)
{
    int length = 0;
    while(number > 0)
    {
        length++;
        number = number / 10;
    }

    return length;
}

long getNextHigherBoundry(int length)
{
    return pow(10, length);
}

long getNextLesserBoundry(long input, int length)
{
    int value = 0;

    for(int i=0; i<length - 1; i++)
    {
        value *= 10;
        value += 9;
    }

    return value;
}

long numToBoundry(long input, bool isUpper)
{
    int length = getLengthOfNumber(input);

    if(length % 2 == 1)
    {
        if(isUpper)
        {
            input = getNextLesserBoundry(input, length);
        }
        else
        {
            input = getNextHigherBoundry(length);
        }
    }

    // Length may have changed in boundry functions
    length = getLengthOfNumber(input);

    int halfLength = length / 2;
    long powerOfTen = pow(10, halfLength);

    long bound = input / powerOfTen;

    if(isUpper)
    {
        if(input < (bound * powerOfTen) + bound)
        {
            bound--;
        }
    }
    else
    {
        if(input > (bound * powerOfTen) + bound)
        {
            bound++;
        }
    }

    return bound;
}

struct NumberLine* getNumberLine(long lowerLimit, long upperLimit)
{
    struct NumberLine* numberLine = (struct NumberLine*)malloc(sizeof(struct NumberLine));

    long lowerBound = numToBoundry(lowerLimit, false);
    long upperBound = numToBoundry(upperLimit, true);

    // This happens if lowerLimit and upperLimit have the same odd number of digits
    if(upperBound < lowerBound)
    {
        printf("%ld is less than lower bound %ld. Setting bounds to zero \n", upperBound, lowerBound);
        lowerBound = 0;
        upperBound = 0;
    }

    numberLine->lowerBound = lowerBound;
    numberLine->upperBound = upperBound;

    return numberLine;
}