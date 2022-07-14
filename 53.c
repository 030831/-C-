#include <stdio.h>

int main(){
    int a;
    scanf("%d" , &a ) ;

    while (1){
        printf("%d\n" , a);
        a--;
        if (a==0)
            break;

    }
    return 0;
}