/*
 * File: ec_hw5b.c
 * Name: Chi Chow
 * Date: September 2nd, 2019
 * Sources of help: None
 *
 * Caesar Cipher
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_STR 81
#define ERROR_MSG_NUM_ARGS "Wrong number of arguments"
#define ERROR_MSG_INV_INT "The argument is not a valid integer"
#define ERROR_MSG_INV_SWITCH "Invalid switch"
#define ERROR_MSG_INV_FILE "Error opening file"

#define LETTERS "abcdefghijklmnopqrstuvwxyz"

void printErrorMessages(char *message);

void printCipher(int shift, int lowerCase);

void encrypt(int shift, char *input, char *result);

void encryptFile(char *fileName, int shift);

/*
 * Caesar Cipher
 */
int main(int argc, char *argv[])
{
    int shift;
    char fileSwitch[] = "-f:";
    switch (argc)
    {
        case 2:
            if (sscanf(argv[1], "%d", &shift) != 1)
            {
                printErrorMessages(ERROR_MSG_INV_INT);
                exit(1);
            }
            printCipher(0, 1);
            printCipher(shift, 1);
            printf("\n");
            printCipher(0, 0);
            printCipher(shift, 0);
            break;
        case 3:
            if (sscanf(argv[1], "%d", &shift) != 1)
            {
                printErrorMessages(ERROR_MSG_INV_INT);
                exit(1);
            }
            if (*argv[2] != '-')
            {
                char result[MAX_STR];
                encrypt(shift, argv[2], result);
                printf("%s\n", argv[2]);
                printf("%s\n", result);
            }
            else if (strlen(argv[2]) >= strlen(fileSwitch))
            {
                char possibleSwitch[MAX_STR];
                int fileSwitchLength = strlen(fileSwitch);
                strcpy(possibleSwitch, argv[2]);
                possibleSwitch[fileSwitchLength] = '\0';
                if (strcmp(possibleSwitch, fileSwitch) == 0) //switch detected
                {
                    encryptFile(argv[2] + fileSwitchLength, shift);
                }
            } else
            {
                printErrorMessages(ERROR_MSG_INV_SWITCH);
                exit(1);
            }
            break;
        default:
            printErrorMessages(ERROR_MSG_NUM_ARGS);
            exit(1);
    }

    return 0;
}

void printErrorMessages(char *message)
{
    printf("%s\n", message);
    printf("Usage: hw5b <letter shift> [-f:filename] [string]\n");
}

void printCipher(int shift, int lowerCase)
{
    int i, length = strlen(LETTERS);
    while (shift < 0) shift += length; //convert to positive shift (easier to handle)
    for (i = 0; i < length; i++)
    {
        if (lowerCase)
        {
            printf("%c", tolower(LETTERS[(i + shift) % length]));
        } else
        {
            printf("%c", toupper(LETTERS[(i + shift) % length]));
        }
    }
    printf("\n");
}

void encrypt(int shift, char *input, char *result)
{
    int i, numLetters = strlen(LETTERS), inputLength = strlen(input);
    while (shift < 0) shift += numLetters; //convert to positive shift (easier to handle)
    for (i = 0; i < inputLength; i++)
    {
        int letterIndex = tolower(input[i]) - 'a';
        if (letterIndex >= 0 && letterIndex < numLetters)
        {
            char letter = LETTERS[(letterIndex + shift) % numLetters];
            if (isupper(input[i]))
            {
                result[i] = toupper(letter);
            } else if (islower(input[i]))
            {
                result[i] = tolower(letter);
            }
        } else
        {
            result[i] = input[i];
        }
    }
    result[inputLength] = '\0';
}

void encryptFile(char *fileName, int shift)
{
    if (strlen(fileName) == 0)
    {
        printErrorMessages(ERROR_MSG_INV_SWITCH);
        exit(1);
    }
    FILE *pFile;
    if ((pFile = fopen(fileName, "r")) == (FILE*) NULL)
    {
        printErrorMessages(ERROR_MSG_INV_FILE);
        exit(1);
    }
    char line[MAX_STR], encrypted[MAX_STR];
    while (fgets(line, MAX_STR, pFile))
    {
        encrypt(shift, line, encrypted);
        printf("%s", encrypted);
    }
}
