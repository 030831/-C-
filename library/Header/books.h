//h���� ����ü , ���� , �Լ�����

#pragma once

#ifndef _BOOKS_H_
#define _BOOKS_H_


struct book //å ����ü ����
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



set_books(); // ����ü �����͸� ���� å �̸� , �Ǽ� �Ҵ�
print_books();  //���� �������� å ��� ���
borrow_books(book_input); // å ������ �Լ�
Return_books(); //å �ݳ� �Լ�
Return_books_txt(char* booksname_txt); //�ݳ��� txt���� ���� �Լ�


#endif