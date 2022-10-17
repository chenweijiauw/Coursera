//=============================================================================
//! \brief      Write a C program that has a function that prints a table of values for sine and cosine between (0, 1).
//!             You will upload your program as a text file.
//!
//! \date       Sep 2022
//!
//! \author     Weijia Chen
//=============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <math.h> /* has  sin(), cos() */
int main(void)
{
  double interval;
  int i;
  for (i = 0; i <= 30; i++)
  {
    interval = i / 30.0;
    printf("sin( %lf ) = %lf \t", interval, sin(interval));
    printf("cos( %lf ) = %lf \t", interval, cos(interval));
    printf("\n");
  }

  printf("\n+++++++\n");
  return 0;
}