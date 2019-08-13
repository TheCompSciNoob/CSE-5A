/*
 * File: ec_hw2a.c
 * Name: Chi Chow
 * DateL August 13th, 2019
 * Sources of help: None
 *
 * Customize a pizza and calculate the cost of tye pizza based on the number of toppings selected.
 */

#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

//Function prototypes
void displayMenu();

char getCharInput();

double getDoubleInput();

double areaSquare(double width);

double areaRectangle(double width, double height);

double areaCircle(double radius);

double surfaceAreaCube(double width);

double surfaceAreaCylinder(double radius, double height);

double volumeCube(double width);

int main()
{
    _Bool done = 0;
    while (!done)
    {
        displayMenu();
        char calculatorChoice = getCharInput();
        double width = 0, height = 0, radius = 0;
        switch (calculatorChoice)
        {
            case 'q':
            case 'Q':
                done = 1;
                break;
            case '1':
                printf("Enter width: ");
                width = getDoubleInput();
                printf("Result: %.2f meters\n\n", areaSquare(width));
                break;
            case '2':
                printf("Enter width: ");
                width = getDoubleInput();
                printf("Enter height: ");
                height = getDoubleInput();
                printf("Result: %.2f meters\n\n", areaRectangle(width, height));
                break;
            case '3':
                printf("Enter radius: ");
                radius = getDoubleInput();
                printf("Result: %.2f meters\n\n", areaCircle(radius));
                break;
            case '4':
                printf("Enter width: ");
                width = getDoubleInput();
                printf("Result: %.2f meters\n\n", surfaceAreaCube(width));
                break;
            case '5':
                printf("Enter radius: ");
                radius = getDoubleInput();
                printf("Enter height: ");
                height = getDoubleInput();
                printf("Result: %.2f meters\n\n", surfaceAreaCylinder(radius, height));
                break;
            case '6':
                printf("Enter width: ");
                width = getDoubleInput();
                printf("Result: %.2f meters\n\n", volumeCube(width));
                break;
            default:
                printf("Invalid choice\n\n");
                break;
        }
    }

    //exit
    printf("Goodbye!\n\n");
    printf("Press ENTER to exit!");
    getchar();

    return 0;
}

void displayMenu()
{
    //list of options
    char options[][30] = { //20 = length of strings in array
            "Area of a Square",
            "Area of a Rectangle",
            "Area of a Circle",
            "Surface Area of a Cube",
            "Surface Area of a Cylinder",
            "Volume of a Cube"
    };

    //print options
    printf("Geometry Calculator:\n");
    unsigned int optionIndex;
    for (optionIndex = 0; optionIndex < sizeof(options) / sizeof(options[0]); optionIndex++)
    {
        printf("%d) %s\n", optionIndex + 1, options[optionIndex]);
    }
    printf("\nEnter choice (Q/q) to quit: ");
}

char getCharInput()
{
    char input;
    scanf("%c", &input);
    getchar();
    return input;
}

double getDoubleInput()
{
    double input;
    scanf("%lf", &input);
    getchar();
    return input;
}

double areaSquare(double width)
{
    return pow(width, 2);
}

double areaRectangle(double width, double height)
{
    return width * height;
}

double areaCircle(double radius)
{
    return M_PI * pow(radius, 2);
}

double surfaceAreaCube(double width)
{
    return 6 * pow(width, 2);
}

double surfaceAreaCylinder(double radius, double height)
{
    return 2 * M_PI * pow(radius, 2) + 2 * M_PI * radius * height;
}

double volumeCube(double width)
{
    return pow(width, 3);
}