#include <stdio.h>

#define SIZE 10

_Bool enterNumber(int *pNumber);

void getValidNumber(int *pNumber);

void readArray(int arr[], int length);

void displayArray(int arr[], int length);

void reverseGrades(int arr[], int length);

void swapElements(int arr[], int i, int j);

void addBonusPoints(int arr[], int length, int points);

void setValue(int arr[], int index, int value);

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

    //add grade
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

    //keep alive to see output
    printf("\nPress ENTER to exit!");
    getchar();
}

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

void readArray(int arr[], int length)
{
    int i;
    for (i = 0; i < length; i++)
    {
        getValidNumber(&arr[i]);
    }
}

void displayArray(int arr[], int length)
{
    printf("List of grades: ");
    int i;
    for (i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void reverseGrades(int arr[], int length)
{
    printf("\nReversing the grades.\n");
    int i, half = length / 2;
    for (i = 0; i < half; i++)
    {
        swapElements(arr, i, length - i - 1); //offset of 1
    }
}

void swapElements(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void addBonusPoints(int arr[], int length, int points)
{
    int i;
    for (i = 0; i < length; i++)
    {
        arr[i] += points;
    }
}

void setValue(int arr[], int index, int value)
{
    arr[index] = value;
}