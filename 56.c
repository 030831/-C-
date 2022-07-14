#include <stdio.h>

int main(){
    int a;
    scanf("%d" , &a);

    int b=0;
    while (1){
        printf("%d\n" , b);
        b+=1;
        if (b>a)
            break;
    }
    return 0;
}