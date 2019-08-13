/*
 * File: hw1.c
 * Name: Chi Chow
 * Date: August 6th, 2019
 * Sources of help: None
 *
 * Creates a receipt for a book order, including the student's first and last initials, book cost, and total cost.
 * Makes weight conversions between KG and LB.
 */

#include <stdio.h>

#define SALES_TAX_RATE .0775
#define KG_TO_LB 2.2046 //conversion between KG and LB

/*
 * Calculates the total cost of a book order.
 * Perform weight conversions from KG to LB or LB to KG.
 */
int main()
{
    //Part 1
    printf("Part 1:\n\n");

    char firstInitial;
    char lastInitial;
    double bookCost;
    double shippingCost;
    double tax;
    double totalCost;

    printf("Enter the first letter of your first name: ");
    firstInitial = getchar(); //user inputs first initial
    getchar();

    printf("Enter the first letter of your last name: ");
    lastInitial = getchar(); //user inputs last initial
    getchar();

    printf("Enter the cost of the book: ");
    scanf("%lf", &bookCost); //user inputs cost of the book
    getchar();
    printf("Enter the shipping cost: ");
    scanf("%lf", &shippingCost); //user inputs shipping cost of the order
    getchar();

    tax = bookCost * SALES_TAX_RATE; //calculate tax from book cost
    totalCost = bookCost + tax + shippingCost; //calculate total cost of book order

    //print receipt
    printf("\nReceipt for %c. %c.:\n", firstInitial, lastInitial);
    printf("Book:\t\t$%8.2f\nTax:\t\t$%8.2f\nShipping:\t$%8.2f\nTotal:\t\t$%8.2f\n",
           bookCost,
           tax,
           shippingCost,
           totalCost);

    //Part 2
    printf("\nPart 2:\n\n");

    printf("How many weight conversions would you like to perform? ");
    int numConversions = 0;
    scanf("%d", &numConversions); //user inputs number of weight conversions
    getchar();

    //continue to make conversions until the number of conversions requested is reached
    int i;
    for (i = 0; i < numConversions; i++)
    {
        double weight = 0;
        char unit;
        printf("\n[#%d] Enter the weight you want to convert: ", i + 1);
        scanf("%lf", &weight); //user inputs weight
        getchar();
        printf("Is this a pound or kilogram weight? [P/K]: ");
        scanf("%c", &unit); //user inputs unit (KG or LB)
        getchar();
        if (unit == 'K' || unit == 'k')
        {
            printf("%8.2f kg = %8.2f lb\n", weight, weight * KG_TO_LB); //KG to LB calculation
        } else
        {
            printf("%8.2f lb = %8.2f kg\n", weight, weight / KG_TO_LB); //LB to KG calculation
        }
    }

    //keep the program alive to let user see the output
    printf("\nPress ENTER to quit!");
    getchar();
    return 0;
}