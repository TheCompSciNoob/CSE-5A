/*
 * File: hw2a.c
 * Name: Chi Chow
 * DateL August 13th, 2019
 * Sources of help: None
 *
 * Customize a pizza and calculate the cost of tye pizza based on the number of toppings selected.
 */

#include <stdio.h>

#define PIZZA_COST 10.0
#define TOPPING_COST 1.25
#define NUM_OPTIONS 10

/*
 * Customize a pizza and calculate the cost of tye pizza based on the number of toppings selected.
 */
int main()
{
    printf("Pizza! Pizza!\n");
    printf("Cheese pizza costs $%.2f.", PIZZA_COST);
    printf("Additional toppings cost $%.2f each.\n\n", TOPPING_COST);

    //list of options in an array
    char options[NUM_OPTIONS][20] = { //20 = size of strings in array
            "Place Order",
            "Remove all toppings",
            "Add extra cheese",
            "Add pepperoni",
            "Add sausage",
            "Add bacon",
            "Add mushrooms",
            "Add pineapple",
            "Add bell peppers",
            "Add olives"
    };

    int orderChoice = -1, numToppings = 0;
    double totalCost = PIZZA_COST;
    while (1)
    {
        //Print out possible options with for loop
        unsigned int optionIndex;
        for (optionIndex = 0; optionIndex < NUM_OPTIONS; optionIndex++)
        {
            printf("%d) %s\n", optionIndex, options[optionIndex]);
        }

        //Ask user for input and process order
        printf("\nEnter choice: ");
        scanf("%d", &orderChoice);
        getchar();
        if (orderChoice == 0)
        {
            //exit loop if user chooses place order
            printf("Current price: %.2f\n\n", totalCost);
            break;
        } else if (orderChoice == 1)
        {
            //remove all toppings
            numToppings = 0;
            totalCost = PIZZA_COST;
            printf("%s\n", options[orderChoice]);
            printf("Current price: %.2f\n\n", totalCost);
        } else if (orderChoice >= 2 && orderChoice <= 9)
        {
            //add topping
            numToppings++;
            totalCost += TOPPING_COST;
            printf("%s\n", options[orderChoice]);
            printf("Current price: %.2f\n\n", totalCost);
        } else
        {
            //catch invalid inputs
            printf("Invalid choice\n\n");
        }
    }

    //Print receipt
    printf("You are adding %d extra topping(s) for a total of %.2f\n", numToppings, totalCost);
    printf("Do you wish to order this pizza (y/n)? ");
    char shouldOrder;
    scanf("%c", &shouldOrder);
    getchar();
    if (shouldOrder == 'y')
    {
        printf("\nThank you for your order, your pizza will be ready soon.\n\n");
    } else
    {
        printf("\nYour order has bee canceled, please come again.\n\n");
    }

    //Keep the program alive to see the output
    printf("Press ENTER to exit!");
    getchar();

    return 0;
}
