#include <stdio.h>

int main(){
    int a;
    scanf("%d" , &a);

    int arr[20][20]={0,};

    for (int i=0 ; i<a ; i++){
        int x,y;
        scanf("%d %d" , &x , &y);
        arr[x-1][y-1]=1;
    }

    for (int i=0 ; i<19 ; i++){
        for (int j=0 ; j<19 ; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}