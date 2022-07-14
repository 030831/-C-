#include <stdio.h>

int main(){

    int a;

    scanf("%d" , &a);

    for (int i=1 ; i<=a ; i++){
        
        for (int j=a-1; j>=0 ; j--){
            if (i>j){
                printf("*");
            }
            else if(i<=j){
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;

}