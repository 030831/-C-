// c에는	함수 정의

#include "stdafx.h"
int Return_check = 0;	 //전역 변수

void menu() //메뉴 출력 함수
{

	int menu_input; //메뉴 입력받는 변수

	printf("****************\n\n");
	printf("1. 책 목록 보기\n");
	printf("2. 책 대출\n");
	printf("3. 책 반납\n");
	printf("4. 나가기\n\n");
	printf("****************\n\n");


	printf("메뉴 번호 입력: ");
	scanf_s("%d", &menu_input);
	
	if (menu_input == 4) //메뉴변수가 4일때 프로그램 종료
	{
		printf("프로그램을 종료합니다");

		exit(0); // exit(0)은 '정상종료', exit(1)은 '에러메시지 종료' 

	}
	else if (menu_input == 1)  //메뉴변수가 1일때 책 목록 출력
	{
		system("cls"); // 화면 제거

		print_books();

	}
	else if (menu_input == 2) //메뉴변수가 2일때 책 대출
	{
		system("cls"); // 화면 제거

		char book_input[30];

		Return_check = 1;

		printf("반납하실 책의 이름을 쓰세요: ");

		scanf("%s", book_input);

		borrow_books(book_input);


	}
	else if (menu_input == 3) //메뉴변수가 3일때 책 반납
	{
		system("cls"); // 화면 제거

		if (Return_check == 0)
		{
			printf("반납하실 책이 없습니다\n");
		}
		else if (Return_check == 1)
		{
			Return_books();
		}


	}








}