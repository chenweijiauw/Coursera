//=============================================================================
//! \brief      Write a program that can give the sine of a value between 0 and 1 (non inclusive).
//!             You will be graded based on whether the program can output a value in the correct range
//!             and whether your code is well-formatted and logically correct.
//!
//! \date       Sep 2022
//!
//! \author     Weijia Chen
//=============================================================================
#include <stdio.h>
#include <math.h> // for sin()

#define PI 3.14159265

int main(void)
{
    double x = 0.0, res = 0.0;
    printf("Enter a degree value for x: ");
    scanf("%lf", &x);
    res = sin(x * PI / 180);            // convert degree to radian
    printf("sin(%lf) = %lf\n", x, res); // sin() is in math.h
    return 0;
}