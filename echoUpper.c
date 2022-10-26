#define TITLE “A1Q5_KB.c A1-5 1.00 2022/9/16 Benjamin Kwon”
/***********************************************************************
Assignment 1 Problem 5
Lab Section: X03L
Lab Instructor's Name: Krieger
Program Description: echoUpper.c

echoUpper.c echoes all input lines which contain a given char within the 10th
to 21st characters inclusive, of the line; otherwise, nothing is to be 
displayed, and the program should input the next line. The input lines can be
of any size so you cannot assume a certain length for the line. The input
consists of a character followed by one or more spaces followed by a string.
The line may contain any characters but not start with the space character.

EXAMPLE SESSION:

With n1 = 5 and n2 = 10: 

• input: a bcdeabcdefghijklm 
output: CDEABCDEFGHIJKLM 
• input: a bcdabcdefghijklm 
output: bcdabcdefghijklm 
• input: a bcdefghijabcdef 
output: BCDEFGHIJABCDEF 
• input: a bcdefghijkabcdef 
output: bcdefghijkabcdef 

References:

************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*main function*/
int main()
{
    printf("input: ");
    char c;
    int count = 0;
    char ltr;
    char temparr[50] = {'\0'};
    int ind = 0;
    ltr = getchar();        
    c = getchar();

    /*main loop for looping through stdin*/
    while((c = getchar()))
    {
        if(c==' ' || c=='\t') /*skip spaces and tabs*/ 
             continue;

         temparr[ind] = c;
         /*printf("temparr[ind]: %c\n", temparr[ind]);
           printf("Count: %d\n", count);                 DEV CHK*/

        if (ltr == c && count >= 10 && count <=21)
        {
	  /*printf("If loop entered"); DEV CHK*/
            int i;

	    /*loop to print chars in temparray*/
            for (i = 0; temparr[i] != '\0'; i++)
            {
                printf("%c", toupper(temparr[i]));
            }

	    /*loop to print remaining chars in stdin*/
            while((c = getchar()) != '\n')
            {
                putchar(toupper(c));
            }
        }

        if (c == '\n' || c == EOF)
           break;

        count++;
        ind++;
    }
    printf("\n");
    return 0;
}
