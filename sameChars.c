#define TITLE “A1Q2_KB.c A1-2 1.00 2022/9/16 Banjamin Kwon”
/***********************************************************************
Assignment 1 Problem 2
Lab Section: X03L
Lab Instructor's Name:A.Krieger
Program Description: sameChars.c

Repeatedly input a line consisting of two 
space-separated strings, and determines if the two strings consist of the same 
characters, whether in same or different order
...
EXAMPLE SESSION

• input : abcxyz zaybxc
  output: abcxyz and zaybxc : True

• input : abcxyz zaybc
  output: abcxyz and zaybc : False
...
References:
    1) https://www.programiz.com/c-programming/online-compiler/

    2) https://www.simplilearn.com/tutorials/c-tutorial/c-program-for-bubble-
       sort#:~:text=Bubble%20sort%20in%20C%20is,of%20the%20element%20is%20found.


************************************************************************/
#include <stdio.h>
#include <string.h>

/* Used reference #2 as guide to implement bubble sort which is used to 
sort the arrays in ascending order of chars
EX. char arr[] = [bacde] ---> bubble_sort(arr) = [abcde]*/
void bubble_sort(char str[]) 
{
  unsigned long temp = 0, i, j;
  for (i = 0; i < strlen(str) - 1; i++) 
  {
    for (j = 0; j < strlen(str)-1 -i; j++) 
    {
      if (str[i] > str[j]) 
      {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;

      }
    }
  }
}

/* Checks if two strings are equal, If they are equal, return true, if not,
   return false */
int same_str(char str1[], char str2[])
{
  bubble_sort(str1);
  bubble_sort(str2);
  
  if (strlen(str1) != strlen(str2)) /* Anagrams have equal len */
  {
    return 0;
  }

  unsigned long i;
  for (i = 0; i < strlen(str1); i++)
  {
    if (str1[i] == str2[i])
    {
      return 1;
    };
  }
  
  return 0;
}

/* Main function to check if two strings contain exactly the same chars */
int main()
{
  char str1[50];
  char str2[50];
  char nstr1[50], nstr2[50]; /* copy to prevent updating original strings */
  

  printf("input:    ");
  scanf("%s %s",str1,str2);

  strcpy(nstr1, str1);
  strcpy(nstr2, str2);
  /*printf("copied strings %s and %s\n",nstr1, nstr2); DEV CHK*/
 if (same_str(nstr1, nstr2) == 1)
  {
    printf("output:   %s and %s   : True\n", str1,str2);
  }
    else
    {
      printf("output:   %s and %s   : False\n", str1,str2);
    }
  return 0;
}
