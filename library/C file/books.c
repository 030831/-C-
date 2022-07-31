// c����	�Լ� ����

#include "stdafx.h"
int books_txt_Return[20] = { 0 }; //  å �ݳ� ���� ���� ����
int books_amount[20] = { 0 }; //  å ���� ���� ����
char books_txt[20][20];  //å�̸� ���� ����
int books_count = 0; // å ���� ���� ����


void print_books()  //���� �������� å ��� ���
{

	FILE* pfile = fopen("BookList.txt", "r");  // ���� �б���

	char booksname[30];
	int bookscount;

	printf("\n****************\n");
	printf("å ��� ȭ��\n");
	printf("****************\n\n\n");

	while (feof(pfile) == 0)  //å ��� txt���� ���
	{
		fscanf(pfile, "%s %d", booksname, &bookscount);
		printf("%s %d\n", booksname, bookscount);
	}

	printf("\n");


	fclose(pfile);  // ���� �ݱ�
}

void borrow_books(char *book_input)  // å ������ �Լ�
{
	FILE* pfile = fopen("BookList.txt", "r");  // ���� �б���

	int i = 0; // å ������ �迭�� ����
	books_count = 0;
	
	while (feof(pfile) == 0)  //å ��� txt���� ���
	{
		fscanf(pfile, "%s %d", books_txt[i], &books_amount[i]);


		if (!strcmp(book_input, books_txt[i]))
		{
			//txt������ ������ ���Ⱑ�ɿ���Ȯ�� , ����� txt���� ����
			if (books_amount[i] > 0)
			{
				printf("%s�� ����Ǿ����ϴ�\n", books_txt[i]);
				books_amount[i]--;
				books_txt_Return[i]++;

			}
			else if (books_amount[i] == 0)
			{
				printf("�ش�å�� ������ �Ұ��մϴ�\n");
			}


		}
		books_count++; // å ���� ���� ����
		i++;
	}

	

	fclose(pfile);

	int result = remove("BookList.txt"); // ���� ������	�������� ������ �ٽ� �ۼ�

	FILE* pfile2 = fopen("BookList.txt", "w");  // ���� ������

	for (int i = 0; i < books_count-1; i++)
	{
		fprintf(pfile2, "%s %d\n", books_txt[i] , books_amount[i]);
	}

	fprintf(pfile2, "%s %d", books_txt[books_count-1], books_amount[books_count-1]);


	fclose(pfile2); //���� �ݱ�

}


void Return_books() //å �ݳ� �Լ�
{

	printf("***********************\n\n");
	printf("�ݳ��Ͻ� å�� ���\n\n");

	for (int i = 0; i < books_count; i++)
	{
		if (books_txt_Return[i] > 0)
		{
			printf("%s %d\n", books_txt[i], books_txt_Return[i]);
		}

	}


	printf("***********************\n");
	printf("�ݳ��� å�� �̸��� �Է��ϼ���: ");

	char Return_Book_scanf[20];


	scanf("%s", Return_Book_scanf); //�ݳ��� å �Է�


	for (int i = 0; i < books_count; i++)
	{
		if (!strcmp(Return_Book_scanf, books_txt[i]))
		{

			if (books_txt_Return[i] > 0)
			{
				books_txt_Return[i]--;
				books_amount[i]++;
				Return_books_txt(); //txt ���� �ݳ� ����
				printf("�ݳ��� �Ϸ� �Ǿ����ϴ�\n");

			}
			else if (books_txt_Return[i] == 0)
			{
				printf("�������� ���� å�Դϴ�\n");
			}

		}
	}

}

void Return_books_txt() //�ݳ��� txt���� ���� �Լ�
{


	int result = remove("BookList.txt"); // ���� ������	�������� ������ �ٽ� �ۼ�

	FILE* pfile2 = fopen("BookList.txt", "w");  // ���� ������

	for (int i = 0; i < books_count - 1; i++)
	{
		fprintf(pfile2, "%s %d\n", books_txt[i], books_amount[i]);
	}

	fprintf(pfile2, "%s %d", books_txt[books_count-1], books_amount[books_count-1]);


	fclose(pfile2); //���� �ݱ�

}