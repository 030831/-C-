#include <stdio.h>
#include <math.h>

int main(){
    int a,b,sum=0;
    scanf("%d\n%d" , &a , &b);
    int i;
    if (sqrt(a)==(int)sqrt(a)){
        i=(int) sqrt(a);
    }
    else{
        i=(int) sqrt(a)+1;
    }

    int j=i;

    for ( ; i<=(int)sqrt(b) ; i++){
        sum+=i*i;
    }
    if (sum!=0){
        printf("%d\n%d" , sum , j*j);
    }
    else{
        printf("-1");
    }
    
    return 0;
}