#include <stdio.h>

int main(){

    int arr[11][11];

    for (int i=1 ; i<=10 ; i++){
        for (int j=1 ; j<=10 ; j++){
            scanf("%d" , &arr[i][j]);
        }
    }
    int x=2,y=2;

    while (arr[x][y]!=2){
        arr[x][y]=9;
        if (arr[x][y+1]!=1)
            y++;
        else if (arr[x+1][y]!=1)
            x++;
        else
            break;
        
    }

    arr[x][y]=9;

    for (int i=1 ; i<=10 ; i++){
        for (int j=1 ; j<=10 ; j++){
            printf("%d " , arr[i][j]);
        }
        printf("\n");
    }
}