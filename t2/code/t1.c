#include <stdio.h>
#include <stdlib.h>

int main()
{
    char original[1024]="This is the original string!";
    char unoriginal[1024]="And this is another string!";

    original=unoriginal;

    printf("%s\n",original);
}