#include <stdio.h>

int main(){

    int a,b;
    scanf("%d" , &a);

    int arr[23]={};

    for (int i=0 ; i<a ; i++){
        scanf("%d" , &b);

        arr[b-1]+=1;

    }

    for (int i=0 ; i<23 ; i++){
        printf("%d " , arr[i]);
    }
    return 0;
}