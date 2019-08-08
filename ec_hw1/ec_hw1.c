/*
 * File: ec_hw1.c
 * Name: Chi Chow
 * Date: August 6th, 2019
 * Sources of help: None
 *
 * Creates a receipt for a book order, including the student's first and last initials, book cost, and total cost.
 */

#include <stdio.h>

#define SALES_TAX_RATE .0775
#define KG_TO_LB 2.2046

/*
 * Runs the book order program.
 */
int main()
{
    printf("Part 1:\n\n");

    char firstInitial;
    char lastInitial;
    double bookCost;
    int bookQuantity;
    double shippingCost;
    double tax;
    double totalCost;

    printf("Enter the first letter of your first name: ");
    firstInitial = getchar();
    getchar();

    printf("Enter the first letter of your last name: ");
    lastInitial = getchar();
    getchar();

    printf("Enter the cost of the book: ");
    scanf("%lf", &bookCost);
    getchar();

    printf("Enter the quantity of books: ");
    scanf("%d", &bookQuantity);
    getchar();

    printf("Enter the shipping cost: ");
    scanf("%lf", &shippingCost);
    getchar();

    tax = bookCost * bookQuantity * SALES_TAX_RATE;
    totalCost = bookCost * bookQuantity + tax + shippingCost;

    printf("\nReceipt for %c. %c.:\n", firstInitial, lastInitial);
    printf("Book:\t\t$%8.2f\nQuantity:\t %8d\nTax:\t\t$%8.2f\nShipping:\t$%8.2f\nTotal:\t\t$%8.2f\n",
           bookCost,
           bookQuantity,
           tax,
           shippingCost,
           totalCost
    );

    printf("\nPart 2:\n\n");

    printf("How many weight conversions would you like to perform? ");
    int numConversions = 0;
    scanf("%d", &numConversions);

    int i;
    for (i = 0; i < numConversions; i++)
    {
        double weight = 0;
        char unit;
        printf("\n[#%d] Enter the weight you want to convert: ", i + 1);
        scanf("%lf", &weight);
        getchar();

        _Bool hasValidUnit = 0;
        while (!hasValidUnit)
        {
            printf("Is this a pound or kilogram weight? [P/K]: ");
            scanf("%c", &unit);
            getchar();
            if (unit == 'K' || unit == 'k')
            {
                printf("%8.2f kg = %8.2f lb\n", weight, weight * KG_TO_LB);
                hasValidUnit = 1;
            } else if (unit == 'P' || unit == 'p')
            {
                printf("%8.2f lb = %8.2f kg\n", weight, weight / KG_TO_LB);
                hasValidUnit = 1;
            } else
            {
                printf("Invalid entry!\n");
            }
        }
    }

    printf("\nPress ENTER to quit!");
    getchar();
    return 0;
}
