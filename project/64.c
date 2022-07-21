//69.������Ʈ �ڵ�

#include <stdio.h>
#include <time.h>    // �ð� ��� �������
#include <stdlib.h>  // ������ ��� ��� ����

// 5������ ����̰� �ֽ��ϴ�.
// �ƹ� Ű�� ������ �������� ����̸� �̵� , 5���� ��� �̾Ƽ� Ű��� �����Դϴ�.
// �ߺ� �߻� �����ϸ� ����̸��� ���� �ٸ� Ư¡�� �ֽ��ϴ�.


//Ư¡�� �̸� , ���� , ���� , Ű��� ���̵�(����)�� �����մϴ�.


typedef struct
{
    char *name;   //�̸�
    int age;     //����
    char *characrter; //����
    int level;   //Ű��� ���̵� (1~5)
} CAT;  //����ü�� ������ CAT�� ����


int collections[5]={0,0,0,0,0};  //���� ������ �����
CAT cats[5]; //����� ����Ʈ
void initCats() ; //����� ���� �ʱ�ȭ
void printCat(int selected); //����� ���� ��� �Լ�
int checkCollection(); //����� ��� �̾Ҵ��� Ȯ�� �Լ�


int main()
{
    srand(time(NULL));

    initCats();

    while (1)
    {
        printf("�αٵα�~! ��� ������� ���簡 �ɱ��? \n �ƹ�Ű�� ������ Ȯ���ϼ���!");
        getchar();  //Ű �Է� ���

        int selected=rand()%5; // 0~4���� ���� ��ȯ
        printCat(selected); //���� ����� ��� �Լ�
        collections[selected]=1;   // ����� �̱� ó���ϱ�


        int collectAll= checkCollection(); //����̸� ��� �̾Ҵ��� Ȯ��
        if (collectAll==1) // ����̸� �� ��Ҵٸ� ����
        {
            break;
        }


    }
    return 0;
}

void initCats()
{
    cats[0].name="ƼƼ";
    cats[0].age=5;
    cats[0].characrter="�¼���";
    cats[0].level=1;

    cats[1].name="���";
    cats[1].age=3;
    cats[1].characrter="��ī�ο�";
    cats[1].level=2;

    cats[2].name="���";
    cats[2].age=7;
    cats[2].characrter="�� �Ḹ ��";
    cats[2].level=3;

    cats[3].name="����";
    cats[3].age=2;
    cats[3].characrter="�ò�����";
    cats[3].level=4;

    cats[4].name="���";
    cats[4].age=1;
    cats[4].characrter="�����";
    cats[4].level=5;

}

void printCat(int selected)
{
    printf("\n\n ����� �� ����� ���簡 �Ǿ����ϴ�! ====\n\n");
    printf("�̸�          : %s\n" , cats[selected].name);
    printf("����          : %d\n" , cats[selected].age);
    printf("Ư¡(����)     : %s\n" , cats[selected].characrter);
    printf("����          : ");

    for (int i=0 ; i<=cats[selected].level ; i++)
    {
        printf("%s" , "�� ");
        
    }
    
    printf("\n\n");

}

int checkCollection()
{
    //���� ������ ����� ��� ��� �� �ٸ�Ҵ��� ���� Ȯ��

    int collectAll=1; //���� ����� üũ

    printf("\n\n == ������ ����� ����̿��� ==\n\n");

    for (int i=0; i<5 ; i++)
    {
        if (collections[i]==0)  //����̰� ������ �� �ڽ� ���
        {
            printf("%10s" , "(�� �ڽ�)");
            collectAll=0;  //�� ������ ���� ����


        }
        else   //����̸� ���������� �̸� ���
        {
            printf("%10s" , cats[i].name);
        }


    }
    printf("\n==============================\n\n");

    if (collectAll) //��� ����̸� �������
    {
        printf("\n\n �����մϴ�! ��� ����̸� �� ��ҽ��ϴ�! ������ Ű���ּ���~!\n\n");
    }


    return collectAll;
}