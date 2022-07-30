//h에는 구조체 , 변수 , 함수원형

#pragma once

#ifndef _BOOKS_H_
#define _BOOKS_H_


struct book //책 구조체 선언
{
	char Toeic[6];
	int Toeic_count;

	char Apple[6];
	int Apple_count;

	char English[8];
	int English_count;

	char Math[5];
	int Math_count;

	char Speak[6];
	int Speak_count;

};



set_books(); // 구조체 포인터를 통해 책 이름 , 권수 할당
print_books();  //현재 도서관의 책 목록 출력
borrow_books(book_input); // 책 빌리기 함수
Return_books(); //책 반납 함수
Return_books_txt(char* booksname_txt); //반납후 txt파일 수정 함수


#endif