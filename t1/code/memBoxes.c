#include<stdio.h>
int main()
{
    int x;
    int y;
    x=5;
    y=x;

    /*
    x and y have the same value, but do they have the same memory address?
    */
    printf("%d\n",&x);
    printf("%d\n",&y);
    return 0;
}