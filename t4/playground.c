#include <stdlib.h>
#include <stdio.h>


void func2(char *a, int *x){
    printf("%s\n",a);
    printf("%d\n", &a);

    printf("%d\n",*(a+104));
    //printf("%d\n",(a+108));


    for (int i = 40; i < 200; i++){
        //printf("%d\n",*(a+i));

    }
}

void func1(char *a, int *b){
    char *literal = "akhdlal";
    int x = 700;
    printf("%d %d\n", a, b);
    func2(literal, &x);
    
}


int main(){
    int a = 15;
    int b = 1010;
    char c = 'b';
    printf("my char is %d\n",c);
    func1("asd", &b);
}