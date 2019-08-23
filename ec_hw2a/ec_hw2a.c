/*
 * File: ec_hw2a.c
 * Name: Chi Chow
 * Date: August 13th, 2019
 * Sources of help: None
 *
 * Customize a pizza and calculate the cost of tye pizza based on the number of toppings selected.
 */

#include <stdio.h>

#define PIZZA_COST 10.0
#define TOPPING_COST 1.25
#define MAX_TOPPINGS 6

/*
 * Map option names to actions
 * e.g. "add extra cheese" to "adding extra cheese"
 */
struct Option
{
    char name[25]; //string with defined length
    char action[25]; //string with defined length
};

/*
 * Customize a pizza and calculate the cost of tye pizza based on the number of toppings selected.
 */
int main()
{
    printf("Pizza! Pizza!\n");
    printf("Cheese pizza costs $%.2f.\n", PIZZA_COST);
    printf("Additional toppings cost $%.2f.\n", TOPPING_COST);
    printf("You can add up to 6 toppings.\n\n");

    //list of options in an array
    //map name of option to action of option, e.g. "add extra cheese" to "adding extra cheese"
    struct Option options[] = {
            {.name = "Place Order", .action = ""}, //no action for place order
            {.name = "Remove all toppings", .action = "All toppings removed"},
            {.name = "Add extra cheese", .action = "Adding extra cheese"},
            {.name = "Add pepperoni", .action = "Adding pepperoni"},
            {.name = "Add sausage", .action = "Adding sausage"},
            {.name = "Add bacon", .action = "Adding bacon"},
            {.name = "Add mushrooms", .action = "Adding mushrooms"},
            {.name = "Add pineapple", .action = "Add pineapple"},
            {.name = "Add bell peppers", .action = "Add bell peppers"},
            {.name = "Add olives", .action = "Adding olives"}
    };
    int NUM_OPTIONS = sizeof(options) / sizeof(options[0]); //size of array calculation

    //pizza order cost calculation
    int orderChoice = -1, numToppings = 0;
    double totalCost = PIZZA_COST;
    while (1)
    {
        //Print out possible options with for loop
        int optionIndex;
        for (optionIndex = 0; optionIndex < NUM_OPTIONS; optionIndex++)
        {
            printf("%d) %s\n", optionIndex, options[optionIndex].name);
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
            printf("%s\n", options[orderChoice].action);
            printf("Current price: %.2f\n\n", totalCost);
        } else if (orderChoice >= 2 && orderChoice < NUM_OPTIONS)
        {
            if (numToppings < MAX_TOPPINGS)
            {
                //add topping if there are less than 6 toppings
                numToppings++;
                totalCost += TOPPING_COST;
                printf("%s\n", options[orderChoice].action);
                printf("Current price: %.2f\n\n", totalCost);
            } else
            {
                printf("Maximum toppings reached \n\n");
            }
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
