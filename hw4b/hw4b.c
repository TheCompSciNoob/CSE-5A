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
        printf("\nEnter English phrases: \n");
    } else
    {
        printf("\nEnter Pig Latin phrases: \n");
    }
    char phrase[BUFFER], word[BUFFER], translatedWord[BUFFER];
    while (fgets(phrase, BUFFER, stdin))
    {
        int offset;
        char *pPhrase = phrase;
        while (sscanf(pPhrase, "%s%n", word, &offset) == 1)
        {
            if (translateEnglish)
            {
                englishToPigLatin(word, translatedWord);
            } else
            {
                pigLatinToEnglish(word, translatedWord);
            }
            printf("%s ", translatedWord);
            pPhrase += offset;
        }
        printf("\n\n");
    }
}


/*
 * E -> P-L logic
 */
void englishToPigLatin(char englishWord[], char pigWord[])
{
    strcpy(pigWord, englishWord + 1); //from 1st character of englishWord
    strcat(pigWord, (char[]) {tolower(*englishWord), '\0'}); //add character array
    strcat(pigWord, ENDING); //add ending
    if (isupper(*englishWord)) //lower case to upper case
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
    *pE = *(pigWord + length - endingLength - 1); //3rd last character from pigWord
    strcpy(pE + 1, pigWord); //copy the rest of pigWord into result
    *(englishWord + length - endingLength) = '\0'; //remove ending that was copied in the previous step
    if (isupper(*pigWord)) //lower case to upper case
    {
        *englishWord = toupper(*englishWord);
        *(englishWord + 1) = tolower(*(englishWord + 1));
    }
}