#include <stdio.h>

int main(){
    int a,num,min=24;
    scanf("%d" , &a);
    int arr[a];

    for (int i=0 ; i<a ; i++ ){
        scanf("%d" , &num);
        arr[i]=num;
    }

    for (int i=0 ; i<a ; i++ ){
        if (arr[i]<min){
            min=arr[i];
        }
    }
    printf("%d" , min);
    return 0;

}