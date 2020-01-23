#include <stdio.h>
#include <stdlib.h>
 int main()
 {
    int  array_one[10];
    int  array_two[5];

    // Fill in some values for array two
    for (int i=0; i<5; i++)
    {
       array_two[i]=i;
    }

    array_one=array_two;      // What should happen here?
 }