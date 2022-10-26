#define TITLE “A1Q4_KB.c A1-4 1.00 2022/9/16 Benjamin Kwon”
/***********************************************************************
Assignment 1 Problem 4
Lab Section: X03L
Lab Instructor's Name: Krieger
Program Description: compress.c

inputs a string, consist of lower case chars, compresses it, and outputs a 
string. The compression consists of replacing any sequence of 1 or more of
the same chars by the char itself followed  by a single upper-case 
hex digit indicating the number of times the character is repeated 
(recall that characters ‘A’ to ‘F’ represent values 10 to 15). If a sequence 
longer than 15 identical  characters is encountered, it is replaced by several
 sequences with at most 15 characters each. The  hexadecimal digit is to be 
 represented in uppercase to be distinguished from the letters of the original
text. 

EXAMPLE SESSION

• the string: abcddddddeeefghij should produce the output: abcd6e3fghij 
• the string: aaaaaaaaaaaaaaaaaaaaa should produce the output: aFa6 
• the string: aaaaaaaaaaaaaaaaaaaaabcdddd should produce the output: aFa6bcd4 

References:

************************************************************************/
#include <stdio.h>
#include <string.h>

/*Main function*/
int main()
{
    char str1[100];
    char str2[100] = {"\0"};
    char temp[15];

    printf("Enter a string(max 100 ch): ");
    scanf("%s",&str1);

    int i = 0;

    /*main for loop to loop through length of string*/
    for (i = 0; i < strlen(str1); i++)
    {   
        int count = 1;

	/*keep looping while on same letter*/
        while (i < strlen(str1) - 1 && str1[i] == str1[i + 1])
        {
            count++;
            i++;
        }

	/*main loop for outputting count of letter in string*/
        while (count > 16)
        {
            sprintf(temp, "%cF", str1[i]);
            strcat(str2, temp);
            count -= 15;
        }
        
        if (count == 1)
        {
            sprintf(temp, "%c", str1[i]);
        }
        else if (count < 9)
        {
            sprintf(temp, "%c%d", str1[i], count);
        }
        else if (count < 16)
        {
            sprintf(temp, "%c%c", str1[i], count + 55);
        }
        strcat(str2, temp);
    }
    printf("output: %s\n", str2);

    return 0;
}
