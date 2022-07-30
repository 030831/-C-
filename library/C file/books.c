// c����	�Լ� ����

#include "stdafx.h"
int books_txt_Return[5] = { 0,0,0,0,0}; //���� ���� ����



int set_books() // ����ü �����͸� ���� å �̸� , �Ǽ� �Ҵ�
{
	struct book* BK = malloc(sizeof(struct book)); //���� �޸� �Ҵ�

	strcpy(BK->Toeic, "Toeic");
	strcpy(BK->Apple, "Apple");
	strcpy(BK->English, "English");
	strcpy(BK->Math, "Math");
	strcpy(BK->Speak, "Speak");

	BK -> Toeic_count = 3;
	BK -> Apple_count = 1;
	BK -> English_count = 9;
	BK -> Math_count = 14;
	BK -> Speak_count = 5;

	free(BK);  // ���� �޸� ��ü
}

int print_books()  //���� �������� å ��� ���
{

	FILE* pfile = fopen("books.txt", "r");  // ���� �б���

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

int borrow_books(char *book_input)  // å ������ �Լ�
{
	FILE* pfile = fopen("books.txt", "r");  // ���� �б���


	char books_txt[20];  //å�� ������ ������ ������
	int Toeic_count ;
	int Apple_count;
	int English_count;
	int Math_count;
	int Speak_count;



	fscanf(pfile, "%s %d", books_txt, &Toeic_count);

	//txt������ ������ ���Ⱑ�ɿ���Ȯ�� , ����� txt���� ����

	if (!strcmp(books_txt, book_input))
	{
		if (Toeic_count > 0)
		{
			printf("Toeic�� ����Ǿ����ϴ�\n");
			Toeic_count--;
			Return_books("Toeic", 0); // �������� ���� txt���� ����

		}
		else if (Toeic_count == 0)
		{
			printf("�ش�å�� ������ �Ұ��մϴ�\n");
		}

	}

	fscanf(pfile, "%s %d", books_txt, &Apple_count);

	//txt������ ������ ���Ⱑ�ɿ���Ȯ�� , ����� txt���� ����
	
	if (!strcmp(books_txt, book_input))
	{
		if (Apple_count > 0)
		{
			printf("Apple�� ����Ǿ����ϴ�\n");
			Apple_count--;
			Return_books("Apple", 0); // �������� ���� txt���� ����

		}
		else if (Apple_count == 0)
		{
			printf("�ش�å�� ������ �Ұ��մϴ�\n");
		}

	}

	fscanf(pfile, "%s %d", books_txt, &English_count);

	//txt������ ������ ���Ⱑ�ɿ���Ȯ�� , ����� txt���� ����

	if (!strcmp(books_txt, book_input))
	{
		if (English_count > 0)
		{
			printf("English�� ����Ǿ����ϴ�\n");
			English_count--;
			Return_books("English", 0); // �������� ���� txt���� ����

		}
		else if (English_count == 0)
		{
			printf("�ش�å�� ������ �Ұ��մϴ�\n");
		}

	}

	fscanf(pfile, "%s %d", books_txt, &Math_count);

	//txt������ ������ ���Ⱑ�ɿ���Ȯ�� , ����� txt���� ����

	if (!strcmp(books_txt, book_input))
	{
		if (Math_count > 0)
		{
			printf("Math�� ����Ǿ����ϴ�\n");
			Math_count--;
			Return_books("Math", 0);  // �������� ���� txt���� ����

		}
		else if (Math_count == 0)
		{
			printf("�ش�å�� ������ �Ұ��մϴ�\n");
		}

	}

	fscanf(pfile, "%s %d", books_txt, &Speak_count);
	
	//txt������ ������ ���Ⱑ�ɿ���Ȯ�� , ����� txt���� ����

	if (!strcmp(books_txt, book_input))
	{
		if (Speak_count > 0)
		{
			printf("Speak�� ����Ǿ����ϴ�\n");
			Speak_count--;
			Return_books("Speak", 0);  // �������� ���� txt���� ����

		}
		else if (Speak_count == 0)
		{
			printf("�ش�å�� ������ �Ұ��մϴ�\n");
		}

	}


	fclose(pfile);

	int result = remove("books.txt"); // ���� ������	�������� ������ �ٽ� �ۼ�

	FILE* pfile2 = fopen("books.txt", "w");  // ���� ������


	fprintf(pfile2, "%s %d\n", "Toeic", Toeic_count);
	fprintf(pfile2, "%s %d\n", "Apple", Apple_count);
	fprintf(pfile2, "%s %d\n", "English", English_count);
	fprintf(pfile2, "%s %d\n", "Math", Math_count);
	fprintf(pfile2, "%s %d", "Speak", Speak_count);

	fclose(pfile2); //���� �ݱ�

}


int Return_books(char* book_input, int Return_Book_check) //å �ݳ� �Լ�
{

	//Return_Book_check - > 0�϶� å �ݳ�

	if (Return_Book_check == 0)
	{
		if (!strcmp(book_input, "Toeic"))
		{
			books_txt_Return[0]++;
		}
		else if (!strcmp(book_input, "Apple"))
		{
			books_txt_Return[1]++;
		}
		else if (!strcmp(book_input, "English"))
		{
			books_txt_Return[2]++;
		}
		else if (!strcmp(book_input, "Math"))
		{
			books_txt_Return[3]++;
		}
		else if (!strcmp(book_input, "Speak"))
		{
			books_txt_Return[4]++;
		}
	}

	// Return_Book_check - >  1�϶�	������ å ��� ���

	else if (Return_Book_check == 1)
	{

		printf("***********************\n\n");
		printf("�ݳ��Ͻ� å�� ���\n\n");

		if (books_txt_Return[0] > 0)
		{
			printf("%s %d\n", "Toeic", books_txt_Return[0]);
		}
		if (books_txt_Return[1] > 0)
		{
			printf("%s %d\n", "Apple", books_txt_Return[1]);
		}
		if (books_txt_Return[2] > 0)
		{
			printf("%s %d\n", "English", books_txt_Return[2]);
		}
		if (books_txt_Return[3] > 0)
		{
			printf("%s %d\n", "Math", books_txt_Return[3]);
		}
		if (books_txt_Return[4] > 0)
		{
			printf("%s %d\n", "Speak", books_txt_Return[4]);
		}

		printf("***********************\n");
		printf("�ݳ��� å�� �̸��� �Է��ϼ���: ");

		char Return_Book_scanf[20];

		scanf("%s", Return_Book_scanf); //�ݳ��� å �Է�


		if (!strcmp(Return_Book_scanf, "Toeic"))  //�ݳ� ���� ���� Ȯ��
		{
			if (books_txt_Return[0] > 0)
			{
				books_txt_Return[0]--;
				Return_books_txt("Toeic"); //txt ���� �ݳ� ����
				printf("�ݳ��� �Ϸ� �Ǿ����ϴ�\n");
			}
			else if (books_txt_Return[0] == 0)
			{
				printf("�������� ���� å�Դϴ�\n");
			}
		}
		else if (!strcmp(Return_Book_scanf, "Apple"))  //�ݳ� ���� ���� Ȯ��
		{
			if (books_txt_Return[1]> 0)
			{
				books_txt_Return[1]--;
				Return_books_txt("Apple"); //txt ���� �ݳ� ����
				printf("�ݳ��� �Ϸ� �Ǿ����ϴ�\n");
			}
			else if (books_txt_Return[1] == 0)
			{
				printf("�������� ���� å�Դϴ�\n");
			}
		}
		else if (!strcmp(Return_Book_scanf, "English"))  //�ݳ� ���� ���� Ȯ��
		{
			if (books_txt_Return[2] > 0)
			{
				books_txt_Return[2]--;
				Return_books_txt("English"); //txt ���� �ݳ� ����
				printf("�ݳ��� �Ϸ� �Ǿ����ϴ�\n");
			}
			else if (books_txt_Return[2] == 0)
			{
				printf("�������� ���� å�Դϴ�\n");
			}
		}
		else if (!strcmp(Return_Book_scanf, "Math"))  //�ݳ� ���� ���� Ȯ��
		{
			if (books_txt_Return[3] > 0)
			{
				books_txt_Return[3]--;
				Return_books_txt("Math"); //txt ���� �ݳ� ����
				printf("�ݳ��� �Ϸ� �Ǿ����ϴ�\n");
			}
			else if (books_txt_Return[3] == 0)
			{
				printf("�������� ���� å�Դϴ�\n");
			}
		}
		else if (!strcmp(Return_Book_scanf, "Speak"))  //�ݳ� ���� ���� Ȯ��
		{
			if (books_txt_Return[4] > 0)
			{
				books_txt_Return[4]--;
				Return_books_txt("Speak"); //txt ���� �ݳ� ����
				printf("�ݳ��� �Ϸ� �Ǿ����ϴ�\n");
			}
			else if (books_txt_Return[4] == 0)
			{
				printf("�������� ���� å�Դϴ�\n");
			}
		}

	}



}

int Return_books_txt(char* booksname_txt) //�ݳ��� txt���� ���� �Լ�
{

	FILE* pfile = fopen("books.txt", "r");  // ���� �б���

	// �����б⸦���� �����ؾ��� ���� üũ�ϱ�

	char books_txt[20];
	int Toeic_count_txt;
	int Apple_count_txt;
	int English_count_txt;
	int Math_count_txt;
	int Speak_count_txt;

	fscanf(pfile, "%s %d", books_txt, &Toeic_count_txt);

	if (!strcmp(booksname_txt, "Toeic"))
	{
		Toeic_count_txt++;
	}

	fscanf(pfile, "%s %d", books_txt, &Apple_count_txt);

	if (!strcmp(booksname_txt, "Apple"))
	{
		Apple_count_txt++;
	}

	fscanf(pfile, "%s %d", books_txt, &English_count_txt);

	if (!strcmp(booksname_txt, "English"))
	{
		English_count_txt++;
	}

	fscanf(pfile, "%s %d", books_txt, &Math_count_txt);

	if (!strcmp(booksname_txt, "Math"))
	{
		Math_count_txt++;
	}

	fscanf(pfile, "%s %d", books_txt, &Speak_count_txt);

	if (!strcmp(booksname_txt, "Speak"))
	{
		Speak_count_txt++;
	}


	fclose(pfile);

	int result = remove("books.txt"); 

	FILE* pfile2 = fopen("books.txt", "w");  // ���� ������

	//�ݳ��� txt���� ����
	fprintf(pfile2, "%s %d\n", "Toeic", Toeic_count_txt);
	fprintf(pfile2, "%s %d\n", "Apple", Apple_count_txt);
	fprintf(pfile2, "%s %d\n", "English", English_count_txt);
	fprintf(pfile2, "%s %d\n", "Math", Math_count_txt);
	fprintf(pfile2, "%s %d", "Speak", Speak_count_txt);

	fclose(pfile2); //���ϴݱ�
}