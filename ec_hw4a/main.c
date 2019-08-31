/*
 * File: ec_hw4a.c
 * Name: Chi Chow
 * Date: August 29th, 2019
 * Sources of help: None
 *
 * Adds and removes items from a variable length array.
 */

#include <stdio.h>

#define MAX_SIZE 5

void displayMenu();

void displayList(int *pArray, int length);

void addItemToEnd(int *pArray, int *length, int value);

void insertItemInFront(int *pArray, int *length, int value);

void removeLastItem(int *length);

void removeFirstItem(int *pArray, int *length);

void emptyList(int *length);

void insertItem(int *pArray, int *length, int location, int value);

void removeItem(int *pArray, int *length, int location);


/*
 * Adds and removes items from a variable length array.
 */
int main()
{
    int array[MAX_SIZE], length = 0;
    _Bool done = 0;
    while (!done)
    {
        displayMenu();
        int value, location;
        char option;
        scanf("%c", &option);
        getchar();
        switch (option)
        {
            case 'a':
            case 'A':
                printf("Enter item: ");
                scanf("%d", &value);
                getchar();
                addItemToEnd(array, &length, value);
                displayList(array, length);
                break;
            case 'b':
            case 'B':
                removeLastItem(&length);
                displayList(array, length);
                break;
            case 'c':
            case 'C':
                emptyList(&length);
                displayList(array, length);
                break;
            case 'd':
            case 'D':
                printf("Enter item: ");
                scanf("%d", &value);
                getchar();
                insertItemInFront(array, &length, value);
                displayList(array, length);
                break;
            case 'e':
            case 'E':
                removeFirstItem(array, &length);
                displayList(array, length);
                break;
            case 'f':
            case 'F':
                printf("Enter item: ");
                scanf("%d", &value);
                getchar();
                printf("Enter location: ");
                scanf("%d", &location);
                getchar();
                insertItem(array, &length, location, value);
                displayList(array, length);
                break;
            case 'g':
            case 'G':
                printf("Enter location: ");
                scanf("%d", &location);
                getchar();
                removeItem(array, &length, location);
                displayList(array, length);
                break;
            case 'q':
            case 'Q':
                printf("Goodbye!\n\n");
                done = 1;
                break;
            default:
                printf("Invalid command\n");
                break;
        }
    }

    printf("Press ENTER to exit!");
    getchar();

    return 0;
}

/*
 * Shows options.
 */
void displayMenu()
{
    printf("a) Add item to end of list\n");
    printf("b) Remove last item from list\n");
    printf("c) Empty the list\n");
    printf("d) Insert item in front of the list\n");
    printf("e) Remove first item from list\n");
    printf("f) Add item to location from list\n");
    printf("g) Remove item from a location in list\n");
    printf("q) Quit\n");
    printf("\nEnter choice: ");
}

/*
 * Displays items added to the list.
 */
void displayList(int *pArray, int length)
{
    printf("List:");
    int i;
    for (i = 0; i < length; i++)
    {
        printf(" %d", pArray[i]);
    }
    printf("\n\n");
}

/*
 * Insert item to the end of the array.
 */
void addItemToEnd(int *pArray, int *length, int value)
{
    if (*length >= MAX_SIZE)
    {
        printf("List is full, unable to add new item.\n");
    } else
    {
        pArray[*length] = value;
        (*length)++;
    }
}

/*
 * Insert item to the start of the array.
 */
void insertItemInFront(int *pArray, int *length, int value)
{
    if (*length >= MAX_SIZE)
    {
        printf("List is full, unable to add new item.\n");
    } else
    {
        int i;
        for (i = *length; i >= 1; i--)
        {
            pArray[i] = pArray[i - 1];
        }
        pArray[0] = value;
        (*length)++;
    }
}

/*
 * Remove item at the end of the array.
 */
void removeLastItem(int *length)
{
    if (*length <= 0)
    {
        printf("List is empty, unable to remove last item\n");
    } else
    {
        (*length)--;
    }
}

/*
 * Remove item at the start of the array.
 */
void removeFirstItem(int *pArray, int *length)
{
    if (*length <= 0)
    {
        printf("List is empty, unable to remove last item\n");
    } else
    {
        int i;
        for (i = 0; i < *length - 1; i++)
        {
            pArray[i] = pArray[i + 1];
        }
        (*length)--;
    }
}

/*
 * Clears list.
 */
void emptyList(int *length)
{
    *length = 0;
}

/*
 * Insert item at a specific location in the array.
 */
void insertItem(int *pArray, int *length, int location, int value)
{
    if (*length >= MAX_SIZE)
    {
        printf("List is full, unable to add new item.\n");
    } else if (location > *length || location < 0)
    {
        printf("Invalid location, unable to add new item\n");
    } else
    {
        int i;
        for (i = *length; i > location; i--)
        {
            pArray[i] = pArray[i - 1];
        }
        pArray[location] = value;
        (*length)++;
    }
}

/*
 * Remove item at a specific location in the array.
 */
void removeItem(int *pArray, int *length, int location)
{
    if (*length <= 0)
    {
        printf("List is empty, unable to remove last item\n");
    } else if (location > *length - 1 || location < 0)
    {
        printf("Invalid location, unable to remove item\n");
    } else
    {
        int i;
        for (i = location; i < *length - 1; i++)
        {
            pArray[i] = pArray[i + 1];
        }
        (*length)--;
    }
}