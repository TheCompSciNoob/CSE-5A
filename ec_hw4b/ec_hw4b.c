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
    } else
    {
        printf("\nEnter Pig Latin phrases: \n");
    }
    char phrase[BUFFER], word[BUFFER], translatedWord[BUFFER];
    while (fgets(phrase, BUFFER, stdin))
    {
        int offset = 0;
        while (sscanf(phrase + offset, "%s", word) == 1)
        {
            if (translateEnglish)
            {
                englishToPigLatin(word, translatedWord);
            } else
            {
                pigLatinToEnglish(word, translatedWord);
            }
            printf("%s ", translatedWord);
            offset += strlen(word) + 1;
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
    *englishWord = *(pigWord + length - endingLength - 1); //3rd last character from pigWord
    strcpy(englishWord + 1, pigWord); //copy the rest of pigWord into result
    *(englishWord + length - endingLength) = '\0'; //remove ending that was copied in the previous step
    if (isupper(*pigWord)) //lower case to upper case
    {
        *englishWord = toupper(*englishWord);
        *(englishWord + 1) = tolower(*(englishWord + 1));
    }
}

/*
 * Evaluates whether a word is Pig Latin by its ending.
 */
_Bool isPigLatinWord(char word[])
{
    int length = strlen(word);
    return length >= 3 && strcmp(word + length - strlen(ENDING), ENDING) == 0;
}

/*
 * Evaluates whether a phrase is Pig Latin
 */
void isPigLatin()
{
    printf("\nEnter phrases:\n");
    char phrase[BUFFER], word[BUFFER];
    while (fgets(phrase, BUFFER, stdin))
    {
        _Bool isPigLatin = 1;
        int offset = 0;
        while (sscanf(phrase + offset, "%s", word) == 1)
        {
            if (!isPigLatinWord(word))
            {
                isPigLatin = 0;
                break;
            }
            offset += strlen(word) + 1;
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

/*
 * Determines whether a phrase is English or Pig Latin and auto translates.
 */
void autoTranslatePhrase()
{
    printf("\nEnter phrases:\n");
    char phrase[BUFFER], word[BUFFER], wordTranslation[BUFFER];
    while (fgets(phrase, BUFFER, stdin))
    {
        _Bool isPigLatin = 1;
        int offset = 0;
        char result[BUFFER] = "";
        while (sscanf(phrase + offset, "%s", word) == 1) //loop to see if the phrase is Pig Latin
        {
            //assume it's Pig Latin first, reset if not Pig Latin later
            if (isPigLatin)
            {
                //reset if not Pig Latin
                if (!isPigLatinWord(word))
                {
                    isPigLatin = 0;
                    *result = '\0';
                    offset = 0;
                    continue; //skip translation if not Pig Latin word
                }
                pigLatinToEnglish(word, wordTranslation);

            } else
            {
                englishToPigLatin(word, wordTranslation);
            }
            strcat(result, wordTranslation);
            strcat(result, " "); //separate the words
            offset += strlen(word) + 1;
        }
        printf("%s\n\n", result);
    }
}