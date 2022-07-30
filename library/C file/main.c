#include "stdafx.h"


int main()
{

	if ( setLogin()==1 ) //아이디 비밀번호 확인 틀리면 종료
	{
		while (1)
		{
			menu();  //메뉴 화면 이동
		}
	}
		
	return 0;
}