//=============================================================================
//! \brief      Find and correct the error(s) in the program found by clicking "My Submission".
//!             What you should learn is how integer and double arithmetic work,
//!             including some ideas about conversions.
//!
//! \date       Sep 2022
//!
//! \author     Weijia Chen
//=============================================================================
#include <stdio.h>
#define PI 3.14159
int main(void)
{
    double radius;
    printf("Enter radius:");
    scanf("%lf", &radius);
    printf("volume is : %lf \n\n", 4 * radius * radius * radius / 3);
    return 0;
}