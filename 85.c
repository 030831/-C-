#include <stdio.h>

int main(){

    int arr[10];
    int *pointer=arr;

    int max=0 , num=0;

    for (int i=0 ; i<9 ; i ++){
        scanf("%d" , &pointer[i]);
        if (pointer[i]>max){
            max=pointer[i];
            num=i+1;
        }

    }

    printf("%d\n",max);
    printf("%d" , num);
    return 0;
}

