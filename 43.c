#include <stdio.h>

int main(){
    long long int a,b,c;
    scanf("%lld %lld %lld" , &a, &b , &c);
    printf("%lld" , (a>b ? b:a) > c ? c:(a>b ? b:a));
}