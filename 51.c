#include <stdio.h>

int main(){

    long long int a,b;
    scanf("%lld", &a );

    checkpoint:
        if (a>0){
            scanf("%lld" , &b);
            printf("%lld\n" , b);
            a--;
            goto checkpoint;

        }
    return 0;
}