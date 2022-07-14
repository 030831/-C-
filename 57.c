#include <stdio.h>

int main(){
    int a, sum=0 , b=1;
    scanf("%d" , &a);
    while (1){
        if (b%2==0)
            sum+=b;
        b+=1;
        if (b>a)
            break;
    }
    printf("%d" , sum);

    return 0;

}