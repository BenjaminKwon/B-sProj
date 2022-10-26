#define TITLE “A1Q1_KB.c A1-1 1.00 2022/9/16 Benjamin Kwon”
/***********************************************************************
Assignment 1 Problem 1
Lab Section: X03L
Lab Instructor's Name: A.Krieger
Program Description: monthofyear.c asks the user for a month and year, then
                     prints the month's calender
...
EXAMPLE SESSION

If the input is 9 2016 (September 2016), the output should be (note alignment):
Calendar for September 2016: 30 days.
September 1 falls on a Thu.
Sun Mon Tue Wed Thu Fri Sat
                 1   2   3
 4   5   6   7   8   9  10
 11 12  13  14  15  16  17
 18 19  20  21  22  23  24
 25 26  27  28  29  30
...
References:
    - https://www.programiz.com/c-programming/online-compiler/

************************************************************************/
#include <stdio.h>

/* dayOfWeek - Given int day, month, and year, this determines
the day of the week, where: 0 = Sunday, 1 = Monday, etc */
int day_of_week(int day, int month, int year) 
{
    int a, y, m, dow ;
    a = (14-month) / 12 ;
    y = year - a ;
    m = month + 12*a - 2 ;
    dow = (day + y + y/4 - y/100 + y/400 + 31*m/12) % 7;
    return dow ;
}

/*checks to see if year entered is a leap year, returns true or false*/
int is_leap( int y)
{
    return ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
}

/* Main program to output the month of year */
int main()
{
    int mon, yr;
    const char* months[12]  = {"January", "February", "March", "April", "May",
                              "June","July", "August", "September", "October",
                              "November","December"};
    const char* weekdays[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    int days_mon[13]        = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    
    printf("Enter month and year: ");
    scanf("%d %d", &mon, &yr);

/*calculates day of week as int: Ex. day = 0 = 'sun'*/
    int day = day_of_week(1, mon, yr); 

/*true if year entered is a leap year, change # days in feb to 29*/
    if (is_leap(yr))
       days_mon[2] = 29;
       
    /*printf("Calendar for %s %d: %d days.\n", months[mon-1], yr, days_mon[mon]); dev ck*/
    printf("%s 1 falls on a %s.\n", months[mon-1], weekdays[day]);
    
/*loop to print weekday strings --> sun mon tue wed thu fri sat*/
    int w;
    for(w = 0; w < 7; w++)
    {
        printf("%s ", weekdays[w]);
    }

    printf("\n");

/*calculate starting position of day 1 in calendar output*/
    int start_pos = ((day * 5) + 3) - day;
    /*printf("%d", start_pos);  dev chk*/

/*calculate spaces needed to get '1' to correct position on calendar*/
    int spaces = start_pos - 1;
    int s;
    for (s = 0; s < spaces; s++)
    {
        /*printf("."); dev chk*/
        printf(" ");
    }

/*loop to print days of the month separated by 3 space characters*/
    int j = day - 1;
    int i;
    for (i = 1; i <= days_mon[mon]; i++)
    {
        if (i == 1)
        {
            printf("%d", i);
            j++;
            continue;
        }

        else if (j != 6 )
        {
            printf("%4d", i);
            j++;
            continue;
        }
        
        else if (j == 6)
        {
            printf("\n");
            printf("%3d", i);
            j = 0;
            continue;
        }
    }
    printf("\n");
    return 0 ;
}   

