#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "common.c"

int one_rotate(int currPosition, struct RotationInstruction *instruction)
{
    int newPosition = currPosition + (instruction->numMoves * instruction->direction);

    while(newPosition > MAX_VALUE)
    {
        newPosition = newPosition - (MAX_VALUE + 1);
    }
    while(newPosition < MIN_VALUE)
    {
        newPosition = newPosition + (MAX_VALUE + 1);
    }

    return newPosition;
}

int solvePart1(int lockPosition, FILE* input_file)
{
    int numZeroes = 0;
    int lineNumber = 0;

    char *line;
    unsigned long len;
    long read;

    while((read = getline(&line, &len, input_file)) != -1)
    {
        struct RotationInstruction *instruction = lineToInstruction(line, read-1);

        if(instruction == NULL)
        {
            free(instruction);
            exit(1);
        }

        lockPosition = one_rotate(lockPosition, instruction);

        if(lockPosition == 0)
        {
            numZeroes++;
        }

        lineNumber++;

        free(instruction);
    }

    free(line);

    printf("Read %d lines \n", lineNumber);
    printf("The lock landed on zero %d times \n", numZeroes);

    return numZeroes;
}
