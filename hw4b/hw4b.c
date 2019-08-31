#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFFER 100
#define ENDING "ay"

/*
 * File: hw4b.c
 * Name: Chi Chow
 * Date: August 29th, 2019
 * Sources of help: None
 *
 * Simple English-to-Pig Latin and Pig Latin-to-English translator.
 */

void displayMenu();

void translatePhrase(_Bool translateEnglish);

void englishToPigLatin(char englishWord[], char pigWord[]);

void pigLatinToEnglish(char *pigWord, char *englishWord);

/*
 * Simple English-to-Pig Latin and Pig Latin-to-English translator.
 */
int main()
{
    printf("Welcome to the Pig Latin translator.\n\n");
    _Bool done = 0;
    while (!done)
    {
        displayMenu();
        char option;
        scanf("%c", &option);
        getchar();
        switch (option)
        {
            case 'a':
            case 'A':
                translatePhrase(1);
                break;
            case 'b':
            case 'B':
                translatePhrase(0);
                break;
            case 'q':
            case 'Q':
                done = 1;
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid command\n\n");
                break;
        }
    }

    printf("Press ENTER to exit!");
    getchar();

    return 0;
}

/*
 * Display options.
 */
void displayMenu()
{
    printf("A) Translate from English into Pig Latin\n");
    printf("B) Translate from Pig Latin into English\n");
    printf("Q) Quit\n");
    printf("\nEnter command: ");
}

/*
 * Handles E -> P-L and P-L -> E
 */
void translatePhrase(_Bool translateEnglish)
{
    if (translateEnglish)
    {
        char english[BUFFER], englishWord[BUFFER], pigWord[BUFFER];
        printf("\nEnter English phrases: \n");
        while (fgets(english, BUFFER, stdin))
        {
            int offset;
            char *pS = english;
            while (sscanf(pS, "%s%n", englishWord, &offset) == 1)
            {
                englishToPigLatin(englishWord, pigWord);
                printf("%s ", pigWord);
                pS += offset;
            }
            printf("\n\n");
        }
    } else
    {
        char pigLatin[BUFFER], pigWord[BUFFER], englishWord[BUFFER];
        printf("\nEnter Pig Latin phrases: \n");
        while (fgets(pigLatin, BUFFER, stdin))
        {
            int offset;
            char *pS = pigLatin;
            while (sscanf(pS, "%s%n", pigWord, &offset) == 1)
            {
                pigLatinToEnglish(pigWord, englishWord);
                printf("%s ", englishWord);
                pS += offset;
            }
            printf("\n\n");
        }
    }
}


/*
 * E -> P-L logic
 */
void englishToPigLatin(char englishWord[], char pigWord[])
{
    int length = strlen(englishWord);
    char *pP = pigWord;
    strcpy(pP, englishWord + 1); //from 1st character of englishWord
    *(pP + length - 1) = tolower(*englishWord); //access string like array
    strcpy(pP + length, ENDING); //copy ending to pointer (no '\0')
    if (isupper(*englishWord))
    {
        *pigWord = toupper(*pigWord);
    }
}

/*
 * P-L -> E logic
 */
void pigLatinToEnglish(char *pigWord, char *englishWord)
{
    int length = strlen(pigWord), endingLength = strlen(ENDING); //where the ending starts in Pig Latin
    char *pE = englishWord;
    *pE = *(pigWord + length - endingLength - 1);
    strcpy(pE + 1, pigWord);
    *(englishWord + length - endingLength) = '\0';
    if (isupper(*pigWord))
    {
        *englishWord = toupper(*englishWord);
        *(englishWord + 1) = tolower(*(englishWord + 1));
    }
}