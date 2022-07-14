#include <stdio.h>

int main(){
    int x,y;
    scanf("%d %d" , &x, &y);

    int arr[101][101]={0,};

    int T;
    scanf("%d" , &T);

    for (int i=0 ; i<T ; i++){
        int l,d,xl,yl;
        scanf("%d %d %d %d" , &l , &d , &xl , &yl);
        if (d==0)
            for (int j=0 ; j<l ; j++)
                arr[xl][yl+j]=1;
            
        else if (d==1)
            for (int j=0; j<l ; j++)
                arr[xl+j][yl]=1;
            
        }
        
    for (int i=1 ; i<=x ; i++){
        for (int j=1 ; j<=y ; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

