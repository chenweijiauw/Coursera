//=============================================================================
//! \brief      Open and read a file of integers into an array that is created
//!             with the first integer telling you how many to read.
//!             So  4  9  11  12  15  would mean create an int array size 4 and read in the remaining 4 values into data[].
//!             Then compute their average as a double and their max  as an int.
//!             Print all this out neatly to the screen and to an output file named answer-hw3.
//!
//! \date       Nov 2022
//!
//! \author     Weijia Chen
//=============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // for INT_MIN

int main(void)
{
    FILE *fp = fopen("week4_option1.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file week4_option.txt");
        exit(1);
    }
    int size;
    fscanf(fp, "%d", &size);
    int *data = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        fscanf(fp, "%d", &data[i]);
    }
    fclose(fp);
    int max = INT_MIN;
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (data[i] > max)
            max = data[i];
        sum += data[i];
    }
    double avg = sum / size;
    printf("The average is %f, the max is %d\n", avg, max);
    FILE *fp2 = fopen("answer-hw4.txt", "w");
    if (fp2 == NULL)
    {
        printf("Error opening file answer-hw4.txt");
        exit(1);
    }
    for (int i = 0; i < size; i++)
    {
        fprintf(fp2, "%d ", data[i]);
    }
    fprintf(fp2, "\nThe average is %f, the max is %d\n", avg, max);
    fclose(fp2);
    free(data);
    return 0;
}
