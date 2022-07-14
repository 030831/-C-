#include <stdio.h>

int main(){
    int arr[20][20]={0,};

    for (int i=0 ; i<19 ; i++){
        for (int j=0 ; j<19 ; j++){
            scanf("%d" , &arr[i][j]);

            }
        }

    int a, x,y;

    scanf("%d" , &a);

    for (int i=0 ; i<a ; i++){
        scanf("%d %d" , &x, &y);
        for (int j=0 ; j<19 ; j++){
            if (arr[x-1][j]==1)
                arr[x-1][j]=0;
            
            else
                arr[x-1][j]=1;
        }
        for (int k=0 ; k<19 ; k++){
            if (arr[k][y-1]==1)
                arr[k][y-1]=0;
            else
                arr[k][y-1]=1;
        }


    }

    for (int i=0 ; i<19 ; i++){
        for (int j=0 ; j<19 ; j++){
            printf("%d " , arr[i][j]);

        }
        printf("\n");
    }
    return 0;
}