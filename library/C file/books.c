// c에는	함수 정의

#include "stdafx.h"
int books_txt_Return[20] = { 0 }; //  책 반납 수량 저장 변수
int books_amount[20] = { 0 }; //  책 수량 저장 변수
char books_txt[20][20];  //책이름 저장 변수
int books_count = 0; // 책 개수 저장 뱐수


void print_books()  //현재 도서관의 책 목록 출력
{

	FILE* pfile = fopen("BookList.txt", "r");  // 파일 읽기모드

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

void borrow_books(char *book_input)  // 책 빌리기 함수
{
	FILE* pfile = fopen("BookList.txt", "r");  // 파일 읽기모드

	int i = 0; // 책 수량을 배열에 저장
	books_count = 0;
	
	while (feof(pfile) == 0)  //책 목록 txt파일 출력
	{
		fscanf(pfile, "%s %d", books_txt[i], &books_amount[i]);


		if (!strcmp(book_input, books_txt[i]))
		{
			//txt파일을 읽으며 대출가능여부확인 , 대출시 txt파일 수정
			if (books_amount[i] > 0)
			{
				printf("%s가 대출되었습니다\n", books_txt[i]);
				books_amount[i]--;
				books_txt_Return[i]++;

			}
			else if (books_amount[i] == 0)
			{
				printf("해당책은 대출이 불가합니다\n");
			}


		}
		books_count++; // 책 개수 저장 뱐수
		i++;
	}

	

	fclose(pfile);

	int result = remove("BookList.txt"); // 파일 삭제후	대출후의 내용을 다시 작성

	FILE* pfile2 = fopen("BookList.txt", "w");  // 파일 쓰기모드

	for (int i = 0; i < books_count-1; i++)
	{
		fprintf(pfile2, "%s %d\n", books_txt[i] , books_amount[i]);
	}

	fprintf(pfile2, "%s %d", books_txt[books_count-1], books_amount[books_count-1]);


	fclose(pfile2); //파일 닫기

}


void Return_books() //책 반납 함수
{

	printf("***********************\n\n");
	printf("반납하실 책의 목록\n\n");

	for (int i = 0; i < books_count; i++)
	{
		if (books_txt_Return[i] > 0)
		{
			printf("%s %d\n", books_txt[i], books_txt_Return[i]);
		}

	}


	printf("***********************\n");
	printf("반납할 책의 이름을 입력하세요: ");

	char Return_Book_scanf[20];


	scanf("%s", Return_Book_scanf); //반납할 책 입력


	for (int i = 0; i < books_count; i++)
	{
		if (!strcmp(Return_Book_scanf, books_txt[i]))
		{

			if (books_txt_Return[i] > 0)
			{
				books_txt_Return[i]--;
				books_amount[i]++;
				Return_books_txt(); //txt 파일 반납 수정
				printf("반납이 완료 되었습니다\n");

			}
			else if (books_txt_Return[i] == 0)
			{
				printf("대출하지 않은 책입니다\n");
			}

		}
	}

}

void Return_books_txt() //반납후 txt파일 수정 함수
{


	int result = remove("BookList.txt"); // 파일 삭제후	대출후의 내용을 다시 작성

	FILE* pfile2 = fopen("BookList.txt", "w");  // 파일 쓰기모드

	for (int i = 0; i < books_count - 1; i++)
	{
		fprintf(pfile2, "%s %d\n", books_txt[i], books_amount[i]);
	}

	fprintf(pfile2, "%s %d", books_txt[books_count-1], books_amount[books_count-1]);


	fclose(pfile2); //파일 닫기

}