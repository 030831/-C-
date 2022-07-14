#include <stdio.h>

int main(){
    int a,sum=0 , i=1;
    scanf("%d" , &a );

    while (1){
        sum+=i;
        if (sum>=a){
            printf("%d" , sum);
            break;
        }
        i++;

    }
    return 0;
}