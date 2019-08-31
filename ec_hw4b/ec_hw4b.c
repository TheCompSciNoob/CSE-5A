#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFFER 100
#define ENDING "ay"

/*
 * File: ec_hw4b.c
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

_Bool isPigLatinWord(char word[]);

void isPigLatin();

void autoTranslatePhrase();

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
            case 'c':
            case 'C':
                isPigLatin();
                break;
            case 'd':
            case 'D':
                autoTranslatePhrase();
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
    printf("C) Is phrase Pig Latin?\n");
    printf("D) Translate Phrase Automatically\n");
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
        char english[BUFFER], englishWord[BUFFER], pigWord[BUFFER];
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
        printf("\nEnter Pig Latin phrases: \n");
        char pigLatin[BUFFER], pigWord[BUFFER], englishWord[BUFFER];
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

_Bool isPigLatinWord(char word[])
{
    int length = strlen(word);
    return length >= 3 && strcmp(word + length - strlen(ENDING), ENDING) == 0;
}

void isPigLatin()
{
    printf("\nEnter phrases:\n");
    char phrase[BUFFER], word[BUFFER];
    while (fgets(phrase, BUFFER, stdin))
    {
        _Bool isPigLatin = 1;
        int offset;
        char *pS = phrase;
        while (sscanf(pS, "%s%n", word, &offset) == 1)
        {
            if (!isPigLatinWord(word))
            {
                isPigLatin = 0;
                break;
            }
            pS += offset;
        }
        if (isPigLatin)
        {
            printf("Pig Latin\n\n");
        } else
        {
            printf("Not Pig latin\n\n");
        }
    }
}

void autoTranslatePhrase()
{
    printf("\nEnter phrases:\n");
    char phrase[BUFFER], word[BUFFER], wordTranslation[BUFFER];
    while (fgets(phrase, BUFFER, stdin))
    {
        _Bool isPigLatin = 1;
        int offset;
        char *pS = phrase;
        while (sscanf(pS, "%s%n", word, &offset) == 1)
        {
            if (!isPigLatinWord(word))
            {
                isPigLatin = 0;
                break;
            }
            pS += offset;
        }
        pS = phrase;
        while (sscanf(pS, "%s%n", word, &offset) == 1)
        {
            if (isPigLatin)
            {
                pigLatinToEnglish(word, wordTranslation);
            } else
            {
                englishToPigLatin(word, wordTranslation);
            }
            printf("%s ", wordTranslation);
            pS += offset;
        }
        printf("\n\n");
    }
}