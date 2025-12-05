#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "./NumberLine/numberLine.h"

long long total = 0;

long long getSumFromNumberLine(struct NumberLine* numberLine)
{
    long long sumOfDoubles = 0;

    for(long i=numberLine->lowerBound; i<numberLine->upperBound+1; i++)
    {
        int length = getLengthOfNumber(i);
        sumOfDoubles += (i * pow(10, length)) + i;
    }

    return sumOfDoubles;
}

struct NumberLine* lineToNumberLine(char* line)
{
    char* parts = strtok(line, "-");
    long lower = atol(parts);
    
    parts = strtok(NULL, "-");
    long upper = atol(parts);

    struct NumberLine* numberLine = getNumberLine(lower, upper);

    return numberLine;
}

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        exit(1);
    }

    FILE* input_file = fopen(argv[1], "r");

    char *line;
    unsigned long len;
    long read;

    while((read = getdelim(&line, &len, ',', input_file)) != -1)
    {
        printf("%s \n", line);

        struct NumberLine* numberLine = lineToNumberLine(line);

        printf("%ld, %ld \n", numberLine->lowerBound, numberLine->upperBound);

        total += getSumFromNumberLine(numberLine);

        free(numberLine);
    }

    free(line);
    fclose(input_file);

    printf("Total: %lld \n", total);

    return 0;
}