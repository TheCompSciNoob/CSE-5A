/*
 * File: hw5b.c
 * Name: Chi Chow
 * Date: September 2nd, 2019
 * Sources of help: None
 *
 * Caesar Cipher
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR 81
#define ERROR_MSG_NUM_ARGS "Wrong number of arguments"
#define ERROR_MSG_INV_INT "The argument is not a valid integer"

#define LETTERS "abcdefghijklmnopqrstuvwxyz"
#define MIN_ARGS 2
#define MAX_ARGS 3

void printErrorMessages(char *message);

void printCipher(int shift, int lowerCase);

void encrypt(int shift, char *input, char *result);

_Bool stringToInt(char string[], int *result);

/*
 * Caesar Cipher
 */
int main(int argc, char *argv[])
{
    int shift;
    switch (argc)
    {
        case 2:
            if (!stringToInt(argv[1], &shift))
            {
                printErrorMessages(ERROR_MSG_INV_INT);
                return 1;
            }
            printCipher(0, 1);
            printCipher(shift, 1);
            printf("\n");
            printCipher(0, 0);
            printCipher(shift, 0);
            break;
        case 3:
            if (!stringToInt(argv[1], &shift))
            {
                printErrorMessages(ERROR_MSG_INV_INT);
                return 1;
            }
            char result[MAX_STR];
            encrypt(shift, argv[2], result);
            printf("%s\n", argv[2]);
            printf("%s\n", result);
            break;
        default:
            printErrorMessages(ERROR_MSG_NUM_ARGS);
            return 1;
    }

    return 0;
}

void printErrorMessages(char *message)
{
    printf("%s\n", message);
    printf("Usage: hw5b <letter shift> [string]\n");
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
        int letterIndex = -1;
        if (isupper(input[i]))
        {
            letterIndex = input[i] - 'A';
        } else if (islower(input[i]))
        {
            letterIndex = input[i] - 'a';
        }
        if (letterIndex >= 0 && letterIndex < numLetters)
        {
            if (isupper(input[i]))
            {
                result[i] = toupper(LETTERS[(letterIndex + shift) % numLetters]);
            } else if (islower(input[i]))
            {
                result[i] = tolower(LETTERS[(letterIndex + shift) % numLetters]);
            }
        } else
        {
            result[i] = input[i];
        }
    }
    result[inputLength] = '\0';
}

_Bool stringToInt(char string[], int *result)
{
    int base = 10, _result = 0;
    _Bool isNegative = 0;
    char *pS = string;
    if (*string == '-')
    {
        pS++;
        isNegative = 1;
    }
    for (; *pS; pS++)
    {
        if (!isdigit(*pS))
        {
            return 0;
        }
        _result *= base;
        _result += *pS - '0';
    }
    if (isNegative)
    {
        *result = -_result;
    } else
    {
        *result = _result;
    }
    return 1;
}