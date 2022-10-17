//=============================================================================
//! \brief      Write enumerated types that supports datesâ€”such as december 12.
//!             Then add a function that produces a next day. So nextday(date) of december 12 is december 13.
//!             Also write a function printdate(date) that prints a date legibly.
//!             The function can assume that February has 28 days and it most know how many days are in each month.
//!             Use a struct with two members; one is the month and the second  is the day of the monthâ€”an int (or short).
//!
//! \date       Oct 2022
//!
//! \author     Weijia Chen
//=============================================================================
#include <ctype.h>
#include <stdio.h>
typedef enum month
{
    jan = 1,
    feb,
    mar,
    apr,
    may,
    jun,
    jul,
    aug,
    sep,
    oct,
    nov,
    dec
} month;

typedef struct date
{
    month m;
    int d;
} date;

date nextday(date d)
{
    if ((d.m == jan ||
         d.m == mar ||
         d.m == may ||
         d.m == jul ||
         d.m == aug ||
         d.m == oct) &&
        d.d == 31)
    {
        // Theses months have 31 days (dec excluded)
        d.m++;
        d.d = 1;
    }
    else if ((d.m == apr ||
              d.m == jun ||
              d.m == sep ||
              d.m == nov) &&
             d.d == 30)
    {
        // These months have 30 days
        d.m++;
        d.d == 1;
    }
    else if (d.m == feb && d.d == 28)
    {
        // February has 28 days
        d.m++;
        d.d = 1;
    }
    else if (d.m == dec && d.d == 31)
    {
        // December 31st is the last day of the year
        d.m = jan;
        d.d = 1;
    }
    else
    {
        // All other days
        d.d++;
    }
    return d;
}

void print_month(month m)
{
    switch (m)
    {
    case jan:
        printf("January");
        break;
    case feb:
        printf("February");
        break;
    case mar:
        printf("March");
        break;
    case apr:
        printf("April");
        break;
    case may:
        printf("May");
        break;
    case jun:
        printf("June");
        break;
    case jul:
        printf("July");
        break;
    case aug:
        printf("August");
        break;
    case sep:
        printf("September");
        break;
    case oct:
        printf("October");
        break;
    case nov:
        printf("November");
        break;
    case dec:
        printf("December");
        break;
    default:
        printf("Invalid month");
        break;
    }
}

int main(void)
{
    date d[5] = {{jan, 1}, {feb, 28}, {mar, 14}, {oct, 31}, {dec, 31}};
    for (int i = 0; i < 5; i++)
    {
        printf("Today is: ");
        print_month(d[i].m);
        printf(" %d\n", d[i].d);
        printf("The next day is: ");
        print_month(nextday(d[i]).m);
        printf(" %d\n", nextday(d[i]).d);
    }
    return 0;
}