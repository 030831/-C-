#include <stdio.h>

int main(){

    long long int a,b,c,d;

    scanf("%lld %lld %lld %lld" , &a , &b , &c , &d);

    for (int i=1 ; i<d ; i++){
        a=a*b+c;
    }

    printf("%lld" , a);

    return 0;
}
