#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void reverse(char *input){

    // walk end until you find null char
    char *end = input;
    while (*end){
        end++;
    }
    end--;
    /* IDEA
    ABCDEF\0
    i    e
    h=A
    t=F
    FBCDEA\0
    i    e
    FBCDEA\0
     i  e
    h=B
    t=E
    */
    while (input < end){
        char h = *input;
        char t = *end;
        *input = t;
        *end = h;
        input++;
        end--;
    }
}


int main()
{
    char input[6] = "ABCDEF";
    reverse(input);
    printf("%s\n", input);

}