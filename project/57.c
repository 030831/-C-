#include <stdio.h>

int add();
int sub();
int mul();
int div();

int main()
{

    int a=8;

    printf("%d\n" , add(a,4)); // 8+4=12

    printf("%d\n" , sub(a,4)); // 8-4=4

    printf("%d\n" , mul(a,4)); // 8*4=32

    printf("%d\n" , div(a,4)); // 8/4=2

}


int add(int a, int b)
{
    return a+b;

}

int sub(int a, int b)
{
    return a-b;

}

int mul(int a, int b)
{
    return a*b;

}

int div(int a, int b)
{
    return a/b;

}