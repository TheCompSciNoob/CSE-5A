/*
 * File: hw5a.c
 * Name: Chi Chow
 * Date: September 2nd, 2019
 * Sources of help: None
 *
 * Inventory management system using functions, loops, arrays, strings, and a structure.
 */

#include <stdio.h>
#include <ctype.h>

#define NAME_SIZE 40
#define MAX_ITEMS 10

struct Item
{
    char name[NAME_SIZE];
    int quantity;
    double price;
};

void displayMenu();

_Bool getChoice(struct Item items[], int *pLength);

void addItem(struct Item *items, int *pLength);

void purchaseItem(struct Item items[], int length);

void displayInventory(struct Item items[], int length);

void emailReceipt();

/*
 * Inventory management system using functions, loops, arrays, strings, and a structure.
 */
int main()
{
    struct Item items[MAX_ITEMS];
    int numItems = 0;

    do
    {
        displayMenu();
    } while (!getChoice(items, &numItems));

    printf("\nThanks using Campus Inventory!\n");

    printf("\nPress ENTER to Exit");
    getchar();

    return 0;
}

/*
 * Shows options for user.
 */
void displayMenu()
{
    printf("****************** Campus Inventory ******************\n");
    printf("   0:  Exit\n");
    printf("   1:  Add Item\n");
    printf("   2:  Purchase Item\n");
    printf("   3:  Display Inventory\n");
    printf("   4:  Email Receipt\n");
    printf("*****************************************************\n");
}

/*
 * Get user choice and call the appropriate functions.
 */
_Bool getChoice(struct Item items[], int *pLength)
{
    printf("Enter choice: [0-4]: ");
    int option;
    scanf("%d", &option);
    getchar();
    switch (option)
    {
        case 0:
            return 1;
        case 1:
            addItem(items, pLength);
            return 0;
        case 2:
            purchaseItem(items, *pLength);
            return 0;
        case 3:
            displayInventory(items, *pLength);
            return 0;
        case 4:
            emailReceipt();
            return 0;
        default:
            printf("\nInvalid choice\n");
            return 0;
    }
}

/*
 * Add item to inventory.
 */
void addItem(struct Item items[], int *pLength)
{
    struct Item newItem;
    printf("\nAdd item\n");
    printf("Enter name of the item: ");
    scanf("%s", newItem.name);
    getchar();
    printf("Enter quantity of the item: ");
    scanf("%d", &newItem.quantity);
    getchar();
    printf("Enter price of item: ");
    scanf("%lf", &newItem.price);
    getchar();
    printf("\n");

    items[*pLength] = newItem;
    (*pLength)++;
}

/*
 * Purchase and remove item from inventory.
 */
void purchaseItem(struct Item items[], int length)
{
    printf("\nPurchase Item");
    while (1)
    {
        displayInventory(items, length);
        int itemIndex = 0;
        printf("\nSelect items to purchase [0 to quit]: ");
        scanf("%d", &itemIndex);
        getchar();
        if (itemIndex == 0)
        {
            printf("\n");
            break;
        } else if (itemIndex > 0 && itemIndex <= length)
        {
            struct Item *item = &items[itemIndex - 1];
            if ((*item).quantity > 0)
            {
                (*item).quantity--;
                printf("\n%s was purchased for $%.2f\n", (*item).name, (*item).price);
                printf("%d remaining\n", (*item).quantity);
            } else
            {
                printf("\nThere are no more %s(s) in stock\n", (*item).name);
            }
        } else
        {
            printf("\nInvalid item\n");
        }
    }

}

/*
 * Display contents in the inventory.
 */
void displayInventory(struct Item items[], int length)
{
    printf("\nCampus Inventory:\n");
    int i;
    for (i = 0; i < length; i++)
    {
        struct Item item = items[i];
        printf(" %d) %s\t\t\t\t\t%d $ %8.2f\n", i + 1, item.name, item.quantity, item.price);
    }
    printf("\n");
}

/*
 * Email receipt of the purchase.
 */
void emailReceipt()
{
    printf("\nEmail Receipt\n");
    printf("Enter name to send email to: ");
    char name[NAME_SIZE], *p = name;
    scanf("%s", name);
    for (; *p; p++) *p = tolower(*p);
    printf("\nEmail transaction sent to %s@ucsd.edu\n\n", name);
}
