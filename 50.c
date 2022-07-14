#include <stdio.h>

int main(){
    int a;
    checkpoint:
        scanf("%d" , &a);
        if (a!=0){
            printf("%d\n" , a);
            goto checkpoint;
        }
    return 0;

}