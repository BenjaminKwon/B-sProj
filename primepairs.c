#define TITLE “A1Q3_KB.c A1-3 1.00 2022/9/16 Banjamin Kwon”
/***********************************************************************
Assignment 1 Problem 3
Lab Section: X03L
Lab Instructor's Name:A.Krieger
Program Description: primepairs.c

Inputs integer value n, and prints pairs of prime numbers that
differ by 2, up to, and including, n, if also prime.
...
EXAMPLE SESSION

An input of 50, output would be:
(3, 5)
(5, 7)
(11, 13)
(17, 19)
(29, 31)
(41, 43)
...
References:
    - https://www.programiz.com/c-programming/online-compiler/
    - https://www.studytonight.com/c-programs/c-program-to-check-whether
      -a-number-is-prime-or-not
************************************************************************/
#include <stdio.h>

/* Prime number checker: returns true if a number is prime, returns 
false otherwise */
int is_prime(int Num)
{
    int i;
    int c = 0;

    for (i = 2; i < Num; i++)
    {
        if (Num % i == 0)
        {
            c++;
        }
    }
    if (c == 0)
    {
      /*printf("Its prime"); Dev Chk*/
        return 1;
    }
    else 
    {
      /*printf("Its not prime"); Dev Chk*/
        return 0;
    }
}

/*Main function and loop for printing prime pairs*/
int main()
{
    int i;
    int num;
    
    printf("Enter number for prime pairs: ");
    scanf("%d",&num);
    
    printf("Prime pairs:\n");    
 
    for (i = 2; i < num; i++)
    {
      if(is_prime(i) && is_prime(i + 2)) /*If i and 1 + 2 is prime*/
        {
            printf("(%d, %d)\n", i, i + 2);
        }
    }
  return 0;
}
