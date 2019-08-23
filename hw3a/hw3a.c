/*
 * File: hw3a.c
 * Name: Chi Chow
 * Date: August 22nd, 2019
 * Sources of help: None
 *
 * Take an input of pennies and convert them into dollars, quarters, dimes, and nickels.
 */

#include <stdio.h>

#define PENNIES_PER_DOLLAR 100
#define PENNIES_PER_QUARTER 25
#define PENNIES_PER_DIME 10
#define PENNIES_PER_NICKEL 5

_Bool enterNumber(int *pNumber);

void getValidNumber(int *pNumber);

void getDollars(int *pDollars, int *pPennies);

void getQuarters(int *pQuarters, int *pPennies);

void getDimes(int *pDimes, int *pPennies);

void getNickels(int *pNickels, int *pPennies);

/*
 * Take an input of pennies and convert them into dollars, quarters, dimes, and nickels.
 */
int main()
{
    //get number of pennies from user
    printf("Enter the number of pennies: ");
    int pennies;
    getValidNumber(&pennies);
    if (pennies == 1) //complicated English makes life harder
    {
        printf("Converting %d penny...\n", pennies);
    } else
    {
        printf("Converting %d pennies...\n", pennies);
    }

    //convert to dollars, quarters, dimes, nickels, pennies
    int dollars, quarters, dimes, nickels;
    getDollars(&dollars, &pennies);
    getQuarters(&quarters, &pennies);
    getDimes(&dimes, &pennies);
    getNickels(&nickels, &pennies);

    //print output
    printf("\n%d dollar(s)\n", dollars);
    printf("%d quarter(s)\n", quarters);
    printf("%d dime(s)\n", dimes);
    printf("%d nickel(s)\n", nickels);
    if (pennies == 1) //complicated English makes life harder
    {
        printf("%d penny\n", pennies);
    } else
    {
        printf("%d pennies\n", pennies);
    }

    //keep alive to see output
    printf("\nPress Enter to quit!");
    getchar();
}

/*
 * Tries to get an integer input from the user.
 * If the user gives and invalid input, return false.
 */
_Bool enterNumber(int *pNumber)
{
    int result = scanf("%d", pNumber);
    getchar();
    return result == 1;
}

/*
 * Infinite loop that repeatedly prompts for input until input is an integer.
 */
void getValidNumber(int *pNumber)
{
    while (1)
    {
        _Bool result = enterNumber(pNumber);
        if (result)
        {
            break;
        } else
        {
            printf("Invalid number. Try again: ");
        }
    }
}

/*
 * Calculates the number of dollars from the amount of pennies inputted.
 */
void getDollars(int *pDollars, int *pPennies)
{
    *pDollars = *pPennies / PENNIES_PER_DOLLAR;
    *pPennies %= PENNIES_PER_DOLLAR;
}

/*
 * Calculates the number of quarters from the amount of pennies inputted.
 */
void getQuarters(int *pQuarters, int *pPennies)
{
    *pQuarters = *pPennies / PENNIES_PER_QUARTER;
    *pPennies %= PENNIES_PER_QUARTER;
}

/*
 * Calculates the number of dimes from the amount of pennies inputted.
 */
void getDimes(int *pDimes, int *pPennies)
{
    *pDimes = *pPennies / PENNIES_PER_DIME;
    *pPennies %= PENNIES_PER_DIME;
}

/*
 * Calculates the number of nickels from the amount of pennies inputted.
 */
void getNickels(int *pNickels, int *pPennies)
{
    *pNickels = *pPennies / PENNIES_PER_NICKEL;
    *pPennies %= PENNIES_PER_NICKEL;
}