#include <stdio.h>
#include <time.h>    // �ð� ��� �������
#include <stdlib.h>  // ������ ��� ��� ����


//59.������Ʈ 

/*
10������ ���� �ٸ� ���� (�� ī�� 2�徿)
����ڷκ��� 2���� �Է°��� �޾Ƽ� -> ���� ���� ã���� ī�� ������
��� ���� ���� ã���� ���� ����
�� ���� Ƚ�� �������� �˷��ֱ�
*/


int arrayAnimal[4][5];   // ��ü ī�� 20�� ����
int checkAnimal[4][5];  //���������� ���� Ȯ�� �迭
void initAnimalArray();
char *strAnimal[10];  //�������� ĳ���� 10�� ����
void initAnimalName(); // ���� �̸� ���� �Լ�
void shuffleAnimal(); // ���� ������ ��ġ �Լ�
int getEmptyPosition(); // ī�带 ���鶧 ����ִ� ī�� ��ġ �Լ�
int conv_pos_x(int x);  // �������ڰ� 19�϶� (3,4)�� ��ȯ���ִ� �Լ� 
int conv_pos_y(int y);
void printAnimals(); //���� ��ġ ���
void printQuestions(); // ���� ��� (ī�� ����)
int foundAllAnimal(); //��� ������ �� ã�Ҵ��� ã�� �Լ�

int main()
{

    srand(time(NULL));

    initAnimalArray();
    initAnimalName();

    shuffleAnimal(); 

    int failCount=0; // ����Ƚ��

    while (1)
    {
        int select1=0 ; //����ڰ� ó�� ������ ��
        int select2=0 ; //����ڰ� �ι����� ������ ��

        // printAnimals(); //���� ��ġ ���
        printQuestions(); // ���� ��� (ī�� ����)
        printf("������ ī�� 2���� ������");
        scanf("%d %d" , &select1 , &select2);

        if (select1==select2) // ���� ī�� ���ý� ��ȿ
            continue;

        int firstSelect_x=conv_pos_x(select1);   //ó�� ������ ī���� x��ǥ
        int firstSelect_y=conv_pos_y(select1);    //ó�� ������ ī���� y��ǥ

        int secondSelect_x=conv_pos_x(select2);  //�ι����� ������ ī���� x��ǥ  
        int secondSelect_y=conv_pos_y(select2);  //�ι����� ������ ī���� y��ǥ

        if ( checkAnimal[firstSelect_x][firstSelect_y]==0 && checkAnimal[secondSelect_x][secondSelect_y]==0 // ī�尡 �������� �ʾҴ���
            && arrayAnimal[firstSelect_x][firstSelect_y]==arrayAnimal[secondSelect_x][secondSelect_y])   // �� ������ ������

        {
            printf("\n\n ����! : %s �߰� \n\n" , strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
            checkAnimal[firstSelect_x][firstSelect_y]=1;  //���� ī��� �ߺ������ʰ� �ϱ����ؼ� Ȯ�� ó��
            checkAnimal[secondSelect_x][secondSelect_y]=1; 
        }
        else
        {
            printf("\n\n ��!! Ʋ�Ȱų� �̹� ������ ī���Դϴ� \n");
            printf("%d : %s\n" , select1 , strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
            printf("%d : %s\n" , select2 , strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
            printf("\n\n");

            failCount++; // ���� Ƚ�� 1 �߰�
        }

        if (foundAllAnimal()==1)  // ��� ������ �� ã�Ҵ��� ���� , 1�� �� 0�� ����
        {
            printf("\n\n �����մϴ� ! ��� ������ �� ã�ҽ��ϴ�!\n");
            printf("���ݱ��� �� %d�� �Ǽ��Ͽ����ϴ� \n" , failCount);
            break;
        }
    }

}


void initAnimalArray()
{
    for (int i=0 ; i<4 ; i++)
    {
        for(int j=0 ; j<5 ; j++)
        {
            arrayAnimal[i][j]=-1;

        }
    }
}

void initAnimalName()
{
    strAnimal[0]= "������";
    strAnimal[1]= "�ϸ�";
    strAnimal[2]= "������";
    strAnimal[3]= "�����";
    strAnimal[4]= "����";
    strAnimal[5]= "�ڳ���";
    strAnimal[6]= "�⸰";
    strAnimal[7]= "��Ÿ";
    strAnimal[8]= "Ÿ��";
    strAnimal[9]= "ȣ����";


}

void shuffleAnimal()
{
    for (int i=0 ; i<10 ; i++)
    {
        for (int j=0 ; j<2 ; j++)
        {
            int pos=getEmptyPosition();
            int x=conv_pos_x(pos);
            int y=conv_pos_y(pos);

            arrayAnimal[x][y]=i;

        }
    }
}


int getEmptyPosition() // ��ǥ���� ����� ã��
{

    while (1)
    {
        int randPos=rand()%20; //0~19������ ���� ��ȯ
        int x=conv_pos_x(randPos);
        int y=conv_pos_y(randPos); 

        if (arrayAnimal[x][y]==-1)
        {
            return randPos;
        }

    }

    return 0;
}



int conv_pos_x(int x) 
{
    return x/5;
}


int conv_pos_y(int y)

{
    return y%5; // 19�϶� ���� 3 �������� 4 �̹Ƿ� (3,4)�� ��
}


void printAnimals() //���� ��ġ ���
{

    for (int i=0 ; i<4 ; i++)
    {
        for (int j=0 ; j<5 ; j++)
        {
            printf("%8s" , strAnimal[arrayAnimal[i][j]]);
        }
        printf("\n");
    }
    printf("\n============================'\n\n");
}

void printQuestions() // ���� ��� (ī�� ����)
{


    printf("\n\n(����)\n");
    int seq=0; //  ī�� üũ Ȯ�κ���


    for (int i=0 ; i<4 ; i++)
    {
        for (int j=0 ; j<5 ; j++)  //ī�带 ����� �����̸� ���� �̸� ��� , ���� ������ �������� �޸��� ���ڷ� ���
        {
            if (checkAnimal[i][j]!=0)
            {
                printf("%8s" , strAnimal[arrayAnimal[i][j]]);
            }
            else
            {
                printf("%8d" , seq);
            }
            seq++;
        }
        printf("\n");
    }


}

int foundAllAnimal()
{
    for (int i=0 ; i<4 ; i++)
    {
        for (int j=0 ; j<5 ; j++)
        {
            if (checkAnimal[i][j]==0)
            {
                return 0;
            }
        }
    }

    return 1;
}