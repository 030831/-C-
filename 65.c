#include <stdio.h>

int main(){

    int a,b,c;

    scanf("%d %d %d" , &a, &b , &c );

    printf("%.2f MB" , (float)a*b*c/1024/1024/8);

    return 0;
}