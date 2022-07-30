// c에는	함수 정의

#include "stdafx.h"
int books_txt_Return[5] = { 0,0,0,0,0}; //전역 변수 선언



int set_books() // 구조체 포인터를 통해 책 이름 , 권수 할당
{
	struct book* BK = malloc(sizeof(struct book)); //동적 메모리 할당

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

	free(BK);  // 동적 메모리 해체
}

int print_books()  //현재 도서관의 책 목록 출력
{

	FILE* pfile = fopen("books.txt", "r");  // 파일 읽기모드

	char booksname[30];
	int bookscount;

	printf("\n****************\n");
	printf("책 목록 화면\n");
	printf("****************\n\n\n");

	while (feof(pfile) == 0)  //책 목록 txt파일 출력
	{
		fscanf(pfile, "%s %d", booksname, &bookscount);
		printf("%s %d\n", booksname, bookscount);
	}

	printf("\n");


	fclose(pfile);  // 파일 닫기
}

int borrow_books(char *book_input)  // 책 빌리기 함수
{
	FILE* pfile = fopen("books.txt", "r");  // 파일 읽기모드


	char books_txt[20];  //책과 수량을 저장할 변수들
	int Toeic_count ;
	int Apple_count;
	int English_count;
	int Math_count;
	int Speak_count;



	fscanf(pfile, "%s %d", books_txt, &Toeic_count);

	//txt파일을 읽으며 대출가능여부확인 , 대출시 txt파일 수정

	if (!strcmp(books_txt, book_input))
	{
		if (Toeic_count > 0)
		{
			printf("Toeic가 대출되었습니다\n");
			Toeic_count--;
			Return_books("Toeic", 0); // 대출으로 인한 txt파일 수정

		}
		else if (Toeic_count == 0)
		{
			printf("해당책은 대출이 불가합니다\n");
		}

	}

	fscanf(pfile, "%s %d", books_txt, &Apple_count);

	//txt파일을 읽으며 대출가능여부확인 , 대출시 txt파일 수정
	
	if (!strcmp(books_txt, book_input))
	{
		if (Apple_count > 0)
		{
			printf("Apple가 대출되었습니다\n");
			Apple_count--;
			Return_books("Apple", 0); // 대출으로 인한 txt파일 수정

		}
		else if (Apple_count == 0)
		{
			printf("해당책은 대출이 불가합니다\n");
		}

	}

	fscanf(pfile, "%s %d", books_txt, &English_count);

	//txt파일을 읽으며 대출가능여부확인 , 대출시 txt파일 수정

	if (!strcmp(books_txt, book_input))
	{
		if (English_count > 0)
		{
			printf("English가 대출되었습니다\n");
			English_count--;
			Return_books("English", 0); // 대출으로 인한 txt파일 수정

		}
		else if (English_count == 0)
		{
			printf("해당책은 대출이 불가합니다\n");
		}

	}

	fscanf(pfile, "%s %d", books_txt, &Math_count);

	//txt파일을 읽으며 대출가능여부확인 , 대출시 txt파일 수정

	if (!strcmp(books_txt, book_input))
	{
		if (Math_count > 0)
		{
			printf("Math가 대출되었습니다\n");
			Math_count--;
			Return_books("Math", 0);  // 대출으로 인한 txt파일 수정

		}
		else if (Math_count == 0)
		{
			printf("해당책은 대출이 불가합니다\n");
		}

	}

	fscanf(pfile, "%s %d", books_txt, &Speak_count);
	
	//txt파일을 읽으며 대출가능여부확인 , 대출시 txt파일 수정

	if (!strcmp(books_txt, book_input))
	{
		if (Speak_count > 0)
		{
			printf("Speak가 대출되었습니다\n");
			Speak_count--;
			Return_books("Speak", 0);  // 대출으로 인한 txt파일 수정

		}
		else if (Speak_count == 0)
		{
			printf("해당책은 대출이 불가합니다\n");
		}

	}


	fclose(pfile);

	int result = remove("books.txt"); // 파일 삭제후	대출후의 내용을 다시 작성

	FILE* pfile2 = fopen("books.txt", "w");  // 파일 쓰기모드


	fprintf(pfile2, "%s %d\n", "Toeic", Toeic_count);
	fprintf(pfile2, "%s %d\n", "Apple", Apple_count);
	fprintf(pfile2, "%s %d\n", "English", English_count);
	fprintf(pfile2, "%s %d\n", "Math", Math_count);
	fprintf(pfile2, "%s %d", "Speak", Speak_count);

	fclose(pfile2); //파일 닫기

}


int Return_books(char* book_input, int Return_Book_check) //책 반납 함수
{

	//Return_Book_check - > 0일때 책 반납

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

	// Return_Book_check - >  1일때	대출한 책 목록 출력

	else if (Return_Book_check == 1)
	{

		printf("***********************\n\n");
		printf("반납하실 책의 목록\n\n");

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
		printf("반납할 책의 이름을 입력하세요: ");

		char Return_Book_scanf[20];

		scanf("%s", Return_Book_scanf); //반납할 책 입력


		if (!strcmp(Return_Book_scanf, "Toeic"))  //반납 가능 여부 확인
		{
			if (books_txt_Return[0] > 0)
			{
				books_txt_Return[0]--;
				Return_books_txt("Toeic"); //txt 파일 반납 수정
				printf("반납이 완료 되었습니다\n");
			}
			else if (books_txt_Return[0] == 0)
			{
				printf("대출하지 않은 책입니다\n");
			}
		}
		else if (!strcmp(Return_Book_scanf, "Apple"))  //반납 가능 여부 확인
		{
			if (books_txt_Return[1]> 0)
			{
				books_txt_Return[1]--;
				Return_books_txt("Apple"); //txt 파일 반납 수정
				printf("반납이 완료 되었습니다\n");
			}
			else if (books_txt_Return[1] == 0)
			{
				printf("대출하지 않은 책입니다\n");
			}
		}
		else if (!strcmp(Return_Book_scanf, "English"))  //반납 가능 여부 확인
		{
			if (books_txt_Return[2] > 0)
			{
				books_txt_Return[2]--;
				Return_books_txt("English"); //txt 파일 반납 수정
				printf("반납이 완료 되었습니다\n");
			}
			else if (books_txt_Return[2] == 0)
			{
				printf("대출하지 않은 책입니다\n");
			}
		}
		else if (!strcmp(Return_Book_scanf, "Math"))  //반납 가능 여부 확인
		{
			if (books_txt_Return[3] > 0)
			{
				books_txt_Return[3]--;
				Return_books_txt("Math"); //txt 파일 반납 수정
				printf("반납이 완료 되었습니다\n");
			}
			else if (books_txt_Return[3] == 0)
			{
				printf("대출하지 않은 책입니다\n");
			}
		}
		else if (!strcmp(Return_Book_scanf, "Speak"))  //반납 가능 여부 확인
		{
			if (books_txt_Return[4] > 0)
			{
				books_txt_Return[4]--;
				Return_books_txt("Speak"); //txt 파일 반납 수정
				printf("반납이 완료 되었습니다\n");
			}
			else if (books_txt_Return[4] == 0)
			{
				printf("대출하지 않은 책입니다\n");
			}
		}

	}



}

int Return_books_txt(char* booksname_txt) //반납후 txt파일 수정 함수
{

	FILE* pfile = fopen("books.txt", "r");  // 파일 읽기모드

	// 파일읽기를통해 수정해야할 내용 체크하기

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

	FILE* pfile2 = fopen("books.txt", "w");  // 파일 쓰기모드

	//반납후 txt파일 수정
	fprintf(pfile2, "%s %d\n", "Toeic", Toeic_count_txt);
	fprintf(pfile2, "%s %d\n", "Apple", Apple_count_txt);
	fprintf(pfile2, "%s %d\n", "English", English_count_txt);
	fprintf(pfile2, "%s %d\n", "Math", Math_count_txt);
	fprintf(pfile2, "%s %d", "Speak", Speak_count_txt);

	fclose(pfile2); //피일닫기
}