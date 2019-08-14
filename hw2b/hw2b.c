/*
 * File: hw2b.c
 * Name: Chi Chow
 * DateL August 13th, 2019
 * Sources of help: None
 *
 * Calculate the area, surface area, and volume of different shapes.
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

/*
 * Calculate the area, surface area, and volume of different shapes.
 */
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
                done = 1; //end the loop if user enters Q/q
                break;
            case '1': //area of square
                printf("Enter width: ");
                width = getDoubleInput();
                printf("Result: %.2f meters\n\n", areaSquare(width));
                break;
            case '2': //area of rectangle
                printf("Enter width: ");
                width = getDoubleInput();
                printf("Enter height: ");
                height = getDoubleInput();
                printf("Result: %.2f meters\n\n", areaRectangle(width, height));
                break;
            case '3': //area of circle
                printf("Enter radius: ");
                radius = getDoubleInput();
                printf("Result: %.2f meters\n\n", areaCircle(radius));
                break;
            case '4': //surface area of cube
                printf("Enter width: ");
                width = getDoubleInput();
                printf("Result: %.2f meters\n\n", surfaceAreaCube(width));
                break;
            case '5': //surface area of cylinder
                printf("Enter radius: ");
                radius = getDoubleInput();
                printf("Enter height: ");
                height = getDoubleInput();
                printf("Result: %.2f meters\n\n", surfaceAreaCylinder(radius, height));
                break;
            case '6': //volume of cube
                printf("Enter width: ");
                width = getDoubleInput();
                printf("Result: %.2f meters\n\n", volumeCube(width));
                break;
            default: //catch invalid inputs
                printf("Invalid choice\n\n");
                break;
        }
    }

    //Keep the program alive to see the output
    printf("Goodbye!\n\n");
    printf("Press ENTER to exit!");
    getchar();

    return 0;
}

/*
 * Display possible calculations.
 */
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

/*
 * Gets character input from user.
 */
char getCharInput()
{
    char input;
    scanf("%c", &input);
    getchar();
    return input;
}

/*
 * Gets double input from user.
 */
double getDoubleInput()
{
    double input;
    scanf("%lf", &input);
    getchar();
    return input;
}

/*
 * Calculate area of square.
 */
double areaSquare(double width)
{
    return pow(width, 2);
}

/*
 * Calculate area of rectangle.
 */
double areaRectangle(double width, double height)
{
    return width * height;
}

/*
 * Calculate area of circle.
 */
double areaCircle(double radius)
{
    return M_PI * pow(radius, 2);
}

/*
 * Calculate surface area of cube.
 */
double surfaceAreaCube(double width)
{
    return 6 * pow(width, 2);
}

/*
 * Calculate surface area of cylinder.
 */
double surfaceAreaCylinder(double radius, double height)
{
    return 2 * M_PI * pow(radius, 2) + 2 * M_PI * radius * height;
}

/*
 * Calculate volume of cube.
 */
double volumeCube(double width)
{
    return pow(width, 3);
}