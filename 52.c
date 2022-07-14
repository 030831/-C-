#include <stdio.h>

int main(){
    long long int a;

    while (1){
        scanf("%lld ", &a);
        if (a!=0){
            printf("%lld\n", a);
        }
        else
            break;
    }
    return 0;
}