#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//26 �� ������Ʈ



int main()
{
    srand(time(NULL));

    int num=rand()%100+1; //0~2��ȯ


    printf("%d", num);

    int answer=0; //����

    int chance=5; //��ȸ


    while (1)

    {
        printf("���� ��ȸ�� %d�� ���ҽ��ϴ�\n" , chance--);
        printf("���ڸ� ���纸���� (1~100): \n") ;
        scanf("%d" , &answer);

        if (answer>num)
        {
            printf("Down \n");
        }

        else if (answer<num)
        {
            printf("UP \n");

        }

        else if (answer==num)
        {
            printf("�����Դϴ�! \n");
            break;
        }

        else
        {
            printf("�˼����� ������ �߻��߽��ϴ�. \n ");
        }

        if (chance==0)
        {
            printf("��� ��ȸ�� �� ����ϼ̳׿� , �ƽ��� �й��߽��ϴ�. \n");
            break;
        }
    }


    return 0;
}