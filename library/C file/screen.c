// c����	�Լ� ����

#include "stdafx.h"
int Return_check = 0;	 //���� ����

void menu() //�޴� ��� �Լ�
{

	int menu_input; //�޴� �Է¹޴� ����

	printf("****************\n\n");
	printf("1. å ��� ����\n");
	printf("2. å ����\n");
	printf("3. å �ݳ�\n");
	printf("4. ������\n\n");
	printf("****************\n\n");


	printf("�޴� ��ȣ �Է�: ");
	scanf_s("%d", &menu_input);
	
	if (menu_input == 4) //�޴������� 4�϶� ���α׷� ����
	{
		printf("���α׷��� �����մϴ�");

		exit(0); // exit(0)�� '��������', exit(1)�� '�����޽��� ����' 

	}
	else if (menu_input == 1)  //�޴������� 1�϶� å ��� ���
	{
		system("cls"); // ȭ�� ����

		print_books();

	}
	else if (menu_input == 2) //�޴������� 2�϶� å ����
	{
		system("cls"); // ȭ�� ����

		char book_input[30];

		Return_check = 1;

		printf("�ݳ��Ͻ� å�� �̸��� ������: ");

		scanf("%s", book_input);

		borrow_books(book_input);


	}
	else if (menu_input == 3) //�޴������� 3�϶� å �ݳ�
	{
		system("cls"); // ȭ�� ����

		if (Return_check == 0)
		{
			printf("�ݳ��Ͻ� å�� �����ϴ�\n");
		}
		else if (Return_check == 1)
		{
			Return_books();
		}


	}








}