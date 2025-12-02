// Link to question: https://adventofcode.com/2025/day/1
// Link to input file: https://adventofcode.com/2025/day/1/input

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

const int MIN_VALUE = 0;
const int MAX_VALUE = 99;

struct RotationInstruction
{
    int isRight;
    int numMoves;
};

int rotate(int currPosition, struct RotationInstruction *instruction)
{
    int newPosition = currPosition + (instruction->numMoves * instruction->isRight);

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

struct RotationInstruction* lineToInstruction(char *line, int length)
{
    if(length > 5 || length < 2)
    {
        printf("Encountered string of invalid length %d \n", length);
        return NULL;
    }

    struct RotationInstruction *newInstruction = malloc(sizeof(struct RotationInstruction));

    newInstruction->isRight = tolower(*line) == 'r' ? 1 : -1;

    line++;

    newInstruction->numMoves = strtol(line, (char **)NULL, 10);

    return newInstruction;
}

int main()
{
    int lockPosition = 50;
    int numZeroes = 0;

    FILE* input_file = fopen("input.txt", "r");

    if(input_file == NULL)
    {
        printf("Error opening file \n");
        exit(1);
    }

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

        lockPosition = rotate(lockPosition, instruction);

        if(lockPosition == 0)
        {
            numZeroes++;
        }

        lineNumber++;

        free(instruction);
    }

    free(line);
    fclose(input_file);

    printf("Read %d lines \n", lineNumber);

    printf("The lock landed on zero %d times \n", numZeroes);

    return 0;
}