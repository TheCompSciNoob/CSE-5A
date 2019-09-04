/*
 * File: ec_hw5a.c
 * Name: Chi Chow
 * Date: September 2nd, 2019
 * Sources of help: None
 *
 * Inventory management system using functions, loops, arrays, strings, and a structure.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NAME_SIZE 40
#define MAX_ITEMS 10
#define MAX_RECEIPT_SIZE 2048

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

void updateItem(struct Item items[], int *pSize);

void removeItem(struct Item items[], int *pSize);

void swapItem(struct Item *p1, struct Item *p2);

void purchaseItemsWithReceipt(struct Item *items, int size);

void printReceipt(char *pReceipt);

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
    printf("   5:  Update Item\n");
    printf("   6:  Remove Item\n");
    printf("   7:  Purchase Item With Receipt\n");
    printf("*****************************************************\n");
}

/*
 * Get user choice and call the appropriate functions.
 */
_Bool getChoice(struct Item items[], int *pLength)
{
    printf("Enter choice: [0-7]: ");
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
        case 5:
            updateItem(items, pLength);
            return 0;
        case 6:
            removeItem(items, pLength);
            return 0;
        case 7:
            purchaseItemsWithReceipt(items, *pLength);
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
    struct Item newItem = {
            .name = "",
            .quantity = -1,
            .price = 0
    };
    printf("\nAdd item\n");
    printf("Enter name of item: ");
    scanf("%s", newItem.name);
    getchar();
    while (1)
    {
        printf("Enter quantity of item: ");
        scanf("%d", &newItem.quantity);
        getchar();
        if (newItem.quantity >= 0) break;
        printf("Quantity cannot be less than 0\n");
    }
    while (1)
    {
        printf("Enter price of item: ");
        scanf("%lf", &newItem.price);
        getchar();
        if (newItem.price > 0) break;
        printf("Price must be greater than 0\n");
    }
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

void updateItem(struct Item items[], int *pSize)
{
    printf("\nUpdate Item\n");
    printf("Enter name of item: ");
    char name[NAME_SIZE];
    scanf("%s", name);
    getchar();
    int i;
    for (i = 0; i < *pSize; i++)
    {
        if (strcmp(items[i].name, name) == 0)
        {
            while (1)
            {
                printf("Enter quantity of item: ");
                scanf("%d", &items[i].quantity);
                getchar();
                if (items[i].quantity >= 0) break;
                printf("Quantity cannot be less than 0\n");
            }
            while (1)
            {
                printf("Enter price of item: ");
                scanf("%lf", &items[i].price);
                getchar();
                if (items[i].price > 0) break;
                printf("Price must be greater than 0\n");
            }
            printf("\n");
            return;
        }
    }
    //name does not exist
    printf("Could not find item\n\n");
}

void removeItem(struct Item items[], int *pSize)
{
    printf("\nRemove Item");
    while (1)
    {
        displayInventory(items, *pSize);
        int itemIndex = 0;
        printf("Select items to remove [0 to quit]: ");
        scanf("%d", &itemIndex);
        getchar();
        if (itemIndex == 0)
        {
            printf("\n");
            break;
        } else if (itemIndex > 0 && itemIndex <= *pSize)
        {
            int i;
            for (i = itemIndex - 1; i < *pSize - 1; i++)
            {
                swapItem(&items[i], &items[i + 1]);
            }
            (*pSize)--;
        } else
        {
            printf("\nInvalid item\n");
        }
    }
}

void swapItem(struct Item *p1, struct Item *p2)
{
    struct Item temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void purchaseItemsWithReceipt(struct Item *items, int size)
{
    printf("\nPurchase Item with Receipt");
    char receipt[MAX_RECEIPT_SIZE] = "Campus Inventory Receipt\n";
    double total = 0;
    while (1)
    {
        displayInventory(items, size);
        int itemIndex = 0;
        printf("Select items to purchase [0 to quit]: ");
        scanf("%d", &itemIndex);
        getchar();
        if (itemIndex == 0)
        {
            printf("\n");
            break;
        } else if (itemIndex > 0 && itemIndex <= size)
        {
            struct Item *item = &items[itemIndex - 1];
            if ((*item).quantity > 0)
            {
                //add item to receipt
                sprintf(receipt + strlen(receipt), "%s\t\t\t\t\t$%8.2f\n", item->name, item->price);
                total += item->price;
                //update inventory
                (*item).quantity--;
                printf("\n%d remaining\n", (*item).quantity);
            } else
            {
                printf("\nThere are no more %s(s) in stock\n", (*item).name);
            }
        } else
        {
            printf("\nInvalid item\n");
        }
    }
    if (total > 0)
    {
        sprintf(receipt + strlen(receipt), "Total:\t\t\t\t\t$%8.2f\n", total);
    }
    printReceipt(receipt);
}

void printReceipt(char *pReceipt)
{
    if (strlen(pReceipt) > 0)
    {
        printf("%s\n", pReceipt);
    }
}
