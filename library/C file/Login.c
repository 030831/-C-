// c에는	함수 정의

#include "stdafx.h"



int setLogin()  // 로그인 함수
{

	struct Loginadmin* L1 = malloc(sizeof(struct Loginadmin)); //동적 메모리 할당
	
	strcpy(L1->id, "admin"); 
	strcpy(L1->password, "1234"); //아이디 , 비밀번호 설정
	
	printf("*****도서 관리 프로그램*****\n");
	printf("아이디: ");

	scanf("%s", L1->Login_id); 	// 아이디 입력


	printf("비밀번호: ");

	scanf("%s" , L1->Login_password); //비밀번호 입력



	if (!strcmp(L1->id, L1->Login_id) && !strcmp(L1->password, L1 -> Login_password)) //아이디 비밀번호 확인

	{
		printf("로그인 성공\n");
		return 1;  //일치하면 1을 반환
	
	}
	else
	{
		printf("로그인 실패\n");
		return 0; //일치하지 않으면 0을 반환 , 프로그램 종료
		
	}

	free(L1); //동적 메모리 해체

}





