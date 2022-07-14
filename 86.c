#include <stdio.h>

int main(){
    int x1,x2,x3;
    int y1,y2,y3;

    scanf("%d:%d:%d",&x1,&x2,&x3);

    scanf("%d:%d:%d" , &y1 , &y2 , &y3);


    if (y3<x3){
        y3=y3+60-x3;
        y2--;

    }
    else if(y3>=x3){
        y3-=x3;
    }

    if (y2<x2){
        y2=y2+60-x2;
        y1--;
    }
    else if(y2>=x2){
        y2-=x2;
    }
    if (y1<x1){
        y1=y1+24-x1;
    }
    else if(y1>=x1){
        y1-=x1;
    }
    printf("%02d:%02d:%02d" , y1, y2 , y3);
}