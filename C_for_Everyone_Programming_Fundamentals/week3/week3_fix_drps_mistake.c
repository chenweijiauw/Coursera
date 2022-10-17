//=============================================================================
//! \brief      Find and correct the error(s) in the following program. You will upload your corrected program as a text file.
//!             What you should learn is how to use the math library and importance of types and type conversions.
//!
//! \date       Sep 2022
//!
//! \author     Weijia Chen
//=============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <math.h> /* has  sin(), abs(), and fabs() */
int main(void)
{
    double interval;
    int i;
    for (i = 0; i < 30; i++)
    {
        interval = i / 10.0;
        printf("sin( %lf ) = %lf \t", interval, fabs(sin(interval)));
    }

    printf("\n+++++++\n");
    return 0;
}