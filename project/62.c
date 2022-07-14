#include <stdio.h>
#include <time.h>  // �ð� ��� �������
#include <stdlib.h> // exit ���



/*
����Ⱑ 6���� �ֽ��ϴ�.
���׿� ����ִµ� , �縷���� ����ֱ� ������ ���� ��� ����մϴ�.
���� �� �����ϱ����� ���� ��� ���׿� �־�����մϴ�.
���׿� ���� ��ԵǸ� ����Ⱑ �װ� �˴ϴ�. �ִ��� ���� �ð����� ����⸦ �츮����
*/
// 51. ������Ʈ 
int level;
void printfFished();  //�� ũ�� ��� �Լ�
void initData();  //ó���� ���� �ִ�� ä���ִ� �Լ�
void decreaseWater(long elapsedTime);  //�ð��� �� �������ִ� �Լ�
int checkFishAlive();  //����Ⱑ ��� �׾����� Ȯ�����ִ� �Լ�
int arrayFish[6];   // ����� �迭 ����
int *cursor;  //����� ���׿� ���� �ִ� ����


int main()
{

    long startTime= 0; //���� ���� �ð�

    long totaltime=0 ; //�� ��� �ð�

    long prevtime=0; // ���� ��� �ð� (�ֱٿ� ���� �� �ð� ����)


    int num;

    initData();

    cursor=arrayFish; //cursor[0] ... cursor[1] ...

    startTime=clock(); // ���� �ð���  �и������� ������ ��ȯ

    while (1)
    {
        printfFished();
        printf("��� ���׿� ���� �ֽðھ��?" );
        scanf("%d" , &num);

        if (num<1 || num>6)
        {
            printf("\n �Է� ���� �߸��Ǿ����ϴ�\n");
            continue;
        }


        // �� ��� �ð�
        totaltime=(clock() - startTime)/CLOCKS_PER_SEC; //�� ������ �ٲ���
        printf("�� ����ð� : %ld ��\n" , totaltime);

        // ���� ���� �� �ð�
        prevtime=totaltime-prevtime;
        printf("�ֱ� ��� �ð� : %ld �� \n" , prevtime);

        //������ ���� ����
        decreaseWater(prevtime);

        // ����ڰ� �Է��� ���׿� ���� �ش�.

        if (cursor[num-1]<=0) // ���׿� ���� ���� ������
        {
            printf("%d �� ������ �̹� �׾����ϴ�... ���� �� �� �����ϴ�\n" , num);
        }

        // ������ ���� 0�� �ƴѰ�� , 100�� ���� ������ üũ

        else if (cursor[num-1]+1 <=100)  // ���� ������ 100�����̹Ƿ� +1�� ����
        {
            printf("%d �� ���׿� ���� �ݴϴ�\n\n" , num);

            cursor[num-1]+=1;  // ���� ��


        }

        //�������� �Ұ��� Ȯ�� (�������� 20�ʸ��� �ѹ��� ����)

        if (totaltime/20 > level-1)
        {
            level++; // ���� 1 ����
            printf(" *** �� ������ ! ���� %d �������� %d ������ ���׷��̵� �߽��ϴ�! *** \n\n" ,level-1 , level);

            //���� ������ 5�϶� ����

            if (level==5)
            {
                printf("\n\n �����մϴ�. �ְ� ������ �޼��Ͽ����ϴ�. ������ �����մϴ�\n\n");
                exit(0); // ���α׷� ����
            }
        }

        //����Ⱑ �׾����� Ȯ��

        if (checkFishAlive()==0)
        {
            printf("��� ����Ⱑ �׾����ϴ� \n");
            exit(0);  //����Ⱑ �����Ƿ� ���� ����
        }
        else
        {
            printf("����Ⱑ ���� ����־��!\n"); // �ּ� �Ѹ��� �̻��� ������ ��� ����
        }

        prevtime=totaltime;  // 10��-> 15�� (5��: prevtime) - > 25�ʰ� ����. ���� 10�ʸ� ���� ���������� , prevtime -> 15�ʷ� , 25��-15�ʴ� 10��


    }

    return 0;

      
}




void initData()
{
    level=1 ; //���ӷ��� 1~5

    for (int i=0 ; i<6 ; i++)
    {
        arrayFish[i]=100; //������ �� ���� (0~100)
    }
}


void printfFished()
{
    printf("%3d�� %3d�� %3d�� %3d�� %3d�� %3d��\n" , 1,2,3,4,5,6);
    for (int i=0 ; i<6 ; i++)
    {
        printf(" %4d" , arrayFish[i]);
    }
    printf("\n\n");
}


void decreaseWater(long elapsedTime)
{
    for (int i=0 ; i<6 ; i++)
    {
        arrayFish[i]-= (level*3* (int)elapsedTime);  //3 : ���̵� ������ ���� ��

        if (arrayFish[i]<0)
        {
            arrayFish[i]=0;
        }
    }
}

int checkFishAlive()
{
    for (int i=0 ; i<6 ; i++)
    {
        if (arrayFish[i]>0)
        {
            return 1; //1�� True�� �ǹ���

        }

        return 0; // 0�� False�� �ǹ���
    }
}