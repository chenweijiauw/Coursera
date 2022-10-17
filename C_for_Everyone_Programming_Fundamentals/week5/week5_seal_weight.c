//=============================================================================
//! \brief      In this peer reviewed assignment, you will use an array to calculate
//!             an average from raw data—specifically the average weight of the northern elephant seal (Mirounga angustirostris)
//!
//! \date       Sep 2022
//!
//! \author     Weijia Chen
//=============================================================================
#include <stdio.h>

// calculate the average of elephant seal data
void calculateAverage(int *weight, int size)
{
    int i;
    double sum = 0.0;
    printf("total size is %d\n", size);
    for (i = 0; i < size; i++)
    {
        sum += weight[i];
    }
    double average = sum / (double)size;
    printf("Total size of data is %d, Total weight is %lf, The average weight is %lf\n", size, sum, average);
    return;
}

int main(void)
{
    FILE *file;
    file = fopen("./ELEPHANT_SEAL_DATA.txt", "r");
    int size = 0;
    int weight[2000]; // array to store weights
    if (file == NULL)
    {
        printf("Error opening file"); // if file open fails, drop an error
        return 0;
    }
    while (!feof(file))
    {
        fscanf(file, "%d", &weight[size]);
        size++;
    }
    calculateAverage(weight, size);
    fclose(file);
    return 0;
}