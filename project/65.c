//76. ������Ʈ


//��й�ȣ�� �Է¹޾Ƽ� �´� ��� �ϱ⸦ �а� �ۼ��ϵ��� �մϴ�.
// Ʋ�� ��� ��� �޼����� ǥ���ϰ� �����մϴ�

#include <stdio.h>
#include <conio.h> //getch �Լ� ����� ���� ���̺귯��
#include <string.h>    // strcmp �Լ��� ����� ��� ����
#define MAX 10000 //�ϱ� �ִ� ���̴� 10000���� �ۼ�

int main()
{

    char line[MAX]; //���Ͽ��� �ҷ��� ������ ������ ����
    char contents[MAX]; //�ϱ��忡 �Է��� ����
    char password[20]; //��й�ȣ �Է�


   

    char c; // ��й�ȣ �Է��Ҷ� ������ �뵵 (����ŷ)

    printf("��� �ϱ⿡ ���Ű��� ȯ���մϴ�!\n");
    printf("��й�ȣ�� �Է��ϼ��� : ");

    int i=0;

    while (1)
    {
        c=getch(); // Ű �Է½� �ٷ� ����

        if (c==13)  //13���� �ƽ�Ű�ڵ�� Enter
        {
            break;
        }
        else
        {
            printf("*");
            password[i]=c;
        }
        i++;
    }

    //��й�ȣ : �����ڵ�(skehzheld)
    printf("\n\n == ��й�ȣ Ȯ����... ====\n\n");
    if (strcmp(password , "skehzheld")==0)  //strcmp�� ���� ��й�ȣ Ȯ���ϱ�
    {
        printf("=== ��й�ȣ Ȯ�� �Ϸ� ===\n\n");
        char *fileName="Note.txt";
        FILE *file=fopen(fileName , "a+b"); // ������ ������ ���� , ������ ������ �ڿ��� ���� ���� �߰�

        if (file==NULL)
        {
            printf("���� ���� ����\n");
            return 1;

        }

        while (fgets(line , MAX , file)!=NULL)  // ���� �б�
        {
            printf( "%s" , line);
        }

        printf("\n\n ������ ��� �ۼ��ϼ���! �����ϽǷ��� EXIT�� �Է��ϼ���\n\n");

        while (1)
        {
            scanf("%[^\n]" , contents); // \n�� ������ ������ �о����
            getchar(); // Enter �Է� ó��

            if (strcmp(contents, "EXIT")==0) // EXIT�� �Է��ߴٸ� �׸� �ۼ�
            {
                printf("��� �ϱ� �Է��� �����մϴ�\n\n");
                break;
            } 
            fputs(contents , file); //�ϱ� �ۼ�
            fputs("\n" , file); // ���Ͽ� �ٹٲ� �ֱ�
        }
        
        fclose(file); // ���� �ݱ�

    }
    else // ��й�ȣ�� Ʋ�� ���
    {
        printf(" === ��й�ȣ�� Ʋ�Ƚ��ϴ� ==\n\n");
        
    }

    return 0;
}