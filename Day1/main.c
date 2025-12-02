// Link to question: https://adventofcode.com/2025/day/1
// Link to input file: https://adventofcode.com/2025/day/1/input

#include <stdio.h>
#include <stdlib.h>

#include "partOne.c"
#include "partTwo.c"

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        exit(1);
    }

    int lockPosition = 50;

    FILE* input_file = fopen(argv[1], "r");

    if(input_file == NULL)
    {
        printf("Error opening file \n");
        exit(1);
    }

    int numZeroes = 0;

    printf("Solving part %s \n", argv[2]);
    
    if(*argv[2] == '1')
    {
        numZeroes = solvePart1(lockPosition, input_file);
    }
    else if(*argv[2] == '2')
    {
        numZeroes = solvePart2(lockPosition, input_file);
    }

    fclose(input_file);

    printf("Answer is: %d \n", numZeroes);

    return 0;
}