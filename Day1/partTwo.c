#pragma once

#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "common.c"

int numZeroes = 0;

int two_handle_full_rotations(struct RotationInstruction *instruction)
{
    printf("Handling full rotation");
    int fullRotations = 0;
    while(instruction->numMoves > MAX_VALUE)
    {
        instruction->numMoves -= (MAX_VALUE + 1);
        fullRotations++;
    }
    while(instruction->numMoves < MIN_VALUE)
    {
        instruction->numMoves += (MAX_VALUE + 1);
        fullRotations++;
    }
    return fullRotations;
}

int two_rotate(int currPosition, struct RotationInstruction *instruction)
{
    numZeroes += two_handle_full_rotations(instruction);

    int newPosition = currPosition + (instruction->numMoves * instruction->direction);

    if(instruction->direction == 1)
    {
        if(newPosition > MAX_VALUE)
        {
            newPosition -= (MAX_VALUE + 1);
            numZeroes++;
        }
    }

    if(instruction->direction == -1)
    {
        if(newPosition == 0)
        {
            numZeroes++;
        }
        else if(newPosition < 0)
        {
            newPosition = newPosition + (MAX_VALUE + 1);
            if(currPosition != 0)
            {
                numZeroes++;
            }
        }
    }

    return newPosition;
}

int solvePart2(int lockPosition, FILE* input_file)
{
    int lineNumber = 0;

    char *line;
    unsigned long len;
    long read;

    while((read = getline(&line, &len, input_file)) != -1)
    {
        struct RotationInstruction *instruction = lineToInstruction(line, read);

        if(instruction == NULL)
        {
            free(instruction);
            exit(1);
        }

        lockPosition = two_rotate(lockPosition, instruction);
        
        lineNumber++;

        printf("Lockposition: %d, lineNumber: %d , numZeroes: %d\n", lockPosition, lineNumber, numZeroes);

        free(instruction);
    }

    free(line);

    printf("Read %d lines \n", lineNumber);
    printf("The lock moved to zero %d times \n", numZeroes);

    return numZeroes;
}
