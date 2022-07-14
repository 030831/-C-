#include <stdio.h>

int main(){

    int a,b,c,day=1;

    scanf("%d %d %d" , &a , &b ,&c);

    while (1){

        if (day%a==0 && day%b==0 && day%c==0){
            printf("%d" , day);
            break;
        }
        day++;
    }
    return 0;

}