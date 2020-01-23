#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
Write a function that takes 2 input strings of size 1024 and swaps
their content.
Strings could have different length.
ex.

char a[1024] = "hello\0";
char b[1024] = "today it's very cold\0";
swap(a, b);
printf("a: %s\nb: %s\n", a, b);

>>> OUTPUT
a: today it's very cold
b: hello
*/

void swap(char x[1024], char y[1024])
{
    /*
    copy x to a temp var, copy y to x, copy temp to y
    */
    int i = 0;
    char temp[1024];
    // copy string x to a temp string variable
    while (x[i])
    {
        temp[i] = x[i];
        i++;
    }
    temp[i] = '\0';
    i = 0;
    // copy string y to x
    while (y[i])
    {
        x[i] = y[i];
        i++;
    }
    x[i] = '\0';
    i = 0;
    // copy temp string to y
    while (temp[i])
    {
        y[i] = temp[i];
        i++;
    }
    y[i] = '\0';
}

void swap2(char s1[1024], char s2[1024])
{
    /*
    copy s1 into temp
    copy s2 into s1
    copy temp into s2
    */
    char temp[1024];
    int i;
    for (i; i < strlen(s1); i++)
    {
        temp[i] = s1[i]; 
    }
    temp[i] = '\0';

    i = 0;
    for (i; i < strlen(s2); i++)
    {
        s1[i] = s2[i]; 
    }
    s1[i] = '\0';
    
    i = 0;
    for (i; i < strlen(temp); i++)
    {
        s2[i] = temp[i]; 
    }
    s2[i] = '\0';
}

void swap3(char x[1024], char y[1024])
{
    /*
    same as original swap, but with libraries
    */
    char temp[1024];
    strcpy(temp, x);
    strcpy(x, y);
    strcpy(y,temp);
}


int main()
{
    char a[1024] = "hello\0";
    char b[1024] = "today it's very cold\0";
    // You could also initialize like this
    //strcpy(a, "hello\0");
    //strcpy(b,"today it's very cold\0");

    // Or this
    //char *a = "hello";
    //char *b = "today it's very cold";
    printf("Before swap\n");
    printf("a: %s\nb: %s\n", a, b);
    swap(a, b);
    printf("After swap\n");
    printf("a: %s\nb: %s\n", a, b);
}