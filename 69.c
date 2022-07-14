#include <stdio.h>
#include <math.h>


int main(){
    long a,b,c;

    scanf("%ld %ld %ld" , &a ,&b ,&c);

    printf("%ld" , a*(int)pow(b,c-1));

    return 0;
}