#include <stdio.h>


// 계산기 프로그램

void p(int num);

int main()

{
    int num=2;
    p(num); 

    num=num+3; //2+3의 값은? 5
    p(num);

    num-=1; //5-1의 값은 ? 4
    p(num);

    num*=3; // 4*3의 값은? 12
    p(num);

    num/=6; // 12/6의 값은? 2
    p(num);

    return 0;
}


void p(int num)
{
    printf("num은 %d 입니다\n" ,num);
}