#include <stdio.h>


// ���� ���α׷�

void p(int num);

int main()

{
    int num=2;
    p(num); 

    num=num+3; //2+3�� ����? 5
    p(num);

    num-=1; //5-1�� ���� ? 4
    p(num);

    num*=3; // 4*3�� ����? 12
    p(num);

    num/=6; // 12/6�� ����? 2
    p(num);

    return 0;
}


void p(int num)
{
    printf("num�� %d �Դϴ�\n" ,num);
}