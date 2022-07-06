#include <stdio.h>

int main(){
    long long int a,b;
    scanf("%lld %lld" , &a , &b);

    if (b>=a)
        printf("1");
    else
        printf("0");
}