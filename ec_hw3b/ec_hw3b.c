/*
 * File: hw3b.c
 * Name: Chi Chow
 * Date: August 22nd, 2019
 * Sources of help: None
 *
 * Collects a set of students' grades, displays them to the screen, and performs other operations on those grades.
 */

#include <stdio.h>

#define SIZE 10
#define SORT_SIZE 5

_Bool enterNumber(int *pNumber);

void getValidNumber(int *pNumber);

void readArray(int arr[], int length);

void displayArray(int arr[], int length);

void reverseGrades(int arr[], int length);

void swapElements(int arr[], int i, int j);

void addBonusPoints(int arr[], int length, int points);

void setValue(int arr[], int index, int value);

void sortGrades(int arr[], int length);

void swapGrades(int *p1, int *p2);

/*
 * Collects a set of students' grades, displays them to the screen, and performs other operations on those grades.
 */
int main()
{
    //read grades
    printf("Enter 10 grades: ");
    int grades[SIZE];
    readArray(grades, SIZE);
    displayArray(grades, SIZE);

    //reverse grades
    reverseGrades(grades, SIZE);
    displayArray(grades, SIZE);

    //add bonus points
    printf("\nEnter bonus points: ");
    int points;
    enterNumber(&points);
    addBonusPoints(grades, SIZE, points);
    displayArray(grades, SIZE);

    //change grade
    printf("\n");
    int studentNum, studentGrade;
    while (1)
    {
        printf("Enter student #: ");
        _Bool result = enterNumber(&studentNum);
        if (result && studentNum >= 0 && studentNum < SIZE)
        {
            break;
        }
    }
    printf("Enter grade: ");
    enterNumber(&studentGrade);
    setValue(grades, studentNum, studentGrade);
    printf("\n");
    displayArray(grades, SIZE);

    //sort grades
    printf("\nSorting the first %d grades.\n", SORT_SIZE);
    sortGrades(grades, SORT_SIZE);
    displayArray(grades, SIZE);

    //keep alive to see output
    printf("\nPress ENTER to exit!");
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
            printf("Invalid number. Try again > "); //triangle this time
        }
    }
}

/*
 * Reads int array input from user by calling scanf SIZE times.
 */
void readArray(int arr[], int length)
{
    int i;
    for (i = 0; i < length; i++)
    {
        getValidNumber(&arr[i]);
    }
}

/*
 * Prints all grades.
 */
void displayArray(int arr[], int length)
{
    printf("List of grades: ");
    int i;
    for (i = 0; i < length; i++) //loop through all elements and print
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/*
 * Reverses the grades in the array.
 */
void reverseGrades(int arr[], int length)
{
    printf("\nReversing the grades.\n");
    int i, half = length / 2;
    for (i = 0; i < half; i++) //loop through half of the array and swap with the other half
    {
        swapElements(arr, i, length - i - 1); //last element is at SIZE - 1
    }
}

/*
 * Swap the position of two elements in an array.
 */
void swapElements(int arr[], int i, int j)
{
    int temp = arr[i]; //temporary to store value of arr[i]
    arr[i] = arr[j];
    arr[j] = temp;
}

/*
 * Add bonus points to all grades.
 */
void addBonusPoints(int arr[], int length, int points)
{
    int i;
    for (i = 0; i < length; i++) //loop through and add points to each
    {
        arr[i] += points;
    }
}

/*
 * Set the value of an element on the array.
 */
void setValue(int arr[], int index, int value)
{
    arr[index] = value;
}

void sortGrades(int arr[], int length)
{
    int i, j;
    for (i = 0; i < length; i++)
    {
        for (j = i + 1; j < length; j++)
        {
            if (arr[i] > arr[j])
            {
                swapGrades(&arr[i], &arr[j]);
            }
        }
    }
}

void swapGrades(int *p1, int *p2)
{
    int temp = *p1; //temporary to store value of p1
    *p1 = *p2;
    *p2 = temp;
}