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
    char fileSwitch[] = "-f:"; //detect a shift when the string is matched
    switch (argc)
    {
        case 2:
            if (sscanf(argv[1], "%d", &shift) != 1) //did not enter an int for shift
            {
                printErrorMessages(ERROR_MSG_INV_INT);
                exit(1);
            }
            //print 4 lines of the cipher to demonstrate how it works
            printCipher(0, 1);
            printCipher(shift, 1);
            printf("\n");
            printCipher(0, 0);
            printCipher(shift, 0);
            break;
        case 3:
            if (sscanf(argv[1], "%d", &shift) != 1) //did not enter an int for shift
            {
                printErrorMessages(ERROR_MSG_INV_INT);
                exit(1);
            }
            if (*argv[2] != '-') //did not enter a switch
            {
                char result[MAX_STR];
                encrypt(shift, argv[2], result);
                printf("%s\n", argv[2]);
                printf("%s\n", result);
            }
            else if (strlen(argv[2]) < strlen(fileSwitch)) //entered an invalid switch
            {
                printErrorMessages(ERROR_MSG_INV_SWITCH);
                exit(1);
            } else //entered a potential switch
            {
                char possibleSwitch[MAX_STR];
                int fileSwitchLength = strlen(fileSwitch);
                strcpy(possibleSwitch, argv[2]);
                possibleSwitch[fileSwitchLength] = '\0';
                if (strcmp(possibleSwitch, fileSwitch) == 0) //switch detected
                {
                    encryptFile(argv[2] + fileSwitchLength, shift);
                }
            }
            break;
        default: //incorrect number of arguments
            printErrorMessages(ERROR_MSG_NUM_ARGS);
            exit(1);
    }

    return 0;
}

/*
 * Shows error message and prints usage of the program.
 */
void printErrorMessages(char *message)
{
    printf("%s\n", message);
    printf("Usage: hw5b <letter shift> [-f:filename] [string]\n");
}

/*
 * Prints all letters of the alphabet after shift.
 */
void printCipher(int shift, int lowerCase)
{
    int i, length = strlen(LETTERS);
    while (shift < 0) shift += length; //convert to positive shift (easier to handle)
    for (i = 0; i < length; i++)
    {
        if (lowerCase) //handling lower and upper case letters
        {
            printf("%c", tolower(LETTERS[(i + shift) % length]));
        } else
        {
            printf("%c", toupper(LETTERS[(i + shift) % length]));
        }
    }
    printf("\n");
}

/*
 * Encrypt an input string into result according to shift.
 */
void encrypt(int shift, char *input, char *result)
{
    int i, numLetters = strlen(LETTERS), inputLength = strlen(input);
    while (shift < 0) shift += numLetters; //convert to positive shift (easier to handle)
    for (i = 0; i < inputLength; i++)
    {
        int letterIndex = tolower(input[i]) - 'a';
        if (letterIndex >= 0 && letterIndex < numLetters) //check if it is a letter
        {
            char letter = LETTERS[(letterIndex + shift) % numLetters];
            if (isupper(input[i])) //handling upper lower and upper case letters.
            {
                result[i] = toupper(letter);
            } else if (islower(input[i]))
            {
                result[i] = tolower(letter);
            }
        } else //do not shift if it is not a letter
        {
            result[i] = input[i];
        }
    }
    result[inputLength] = '\0';
}

/*
 * Takes a file name as input and encrypts the file according to shift.
 */
void encryptFile(char *fileName, int shift)
{
    if (strlen(fileName) == 0) //special case when only the switch is entered but not a file name
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
    while (fgets(line, MAX_STR, pFile)) //read file, encrypt, and print result
    {
        encrypt(shift, line, encrypted);
        printf("%s", encrypted);
    }
}
