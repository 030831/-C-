#include <stdio.h>

int main(){
    char a;

    checkpoint:
        scanf("%c " , &a);
        if (a!='q'){
            printf("%c\n", a);
            goto checkpoint;
        }
    printf("q");
    return 0;

}