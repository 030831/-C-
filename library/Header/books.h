//h에는 구조체 , 변수 , 함수원형

#pragma once

#ifndef _BOOKS_H_
#define _BOOKS_H_



void print_books();  //현재 도서관의 책 목록 출력
void borrow_books(char *book_input); // 책 빌리기 함수
void Return_books_txt(); //반납후 txt파일 수정 함수
void Return_books();

#endif

