#pragma once

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>


const int MIN_VALUE = 0;
const int MAX_VALUE = 99;

struct RotationInstruction
{
    int direction;
    int numMoves;
};

struct RotationInstruction* lineToInstruction(char *line, int length)
{
    if(length > 5 || length < 2)
    {
        printf("Encountered string of invalid length %d \n", length);
        return NULL;
    }

    struct RotationInstruction *newInstruction = malloc(sizeof(struct RotationInstruction));

    newInstruction->direction = tolower(*line) == 'r' ? 1 : -1;

    line++;

    newInstruction->numMoves = strtol(line, (char **)NULL, 10);

    return newInstruction;
}