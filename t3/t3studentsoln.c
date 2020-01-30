#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void reverse(char *input){
    char temp;
    int count;
    for (count = 0; *(input + count) !='\0'; count++) {}
    count--;
    for (int x = 0; x <= (count/2); x++)
    {
        temp = *(input + x);
        *(input + x) = *(input + (count - x));
        *(input + (count - x)) = temp;
    }
}


int main()
{
    char input[7] = "ABCDEFG";
    reverse(input);
    printf("%s\n", input);

}