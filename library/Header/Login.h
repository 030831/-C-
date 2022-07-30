//h에는 구조체 , 변수 , 함수원형

#pragma once

#ifndef _LOGIN_H_
#define _LOGIN_H_

struct Loginadmin //로그인 아이디 , 비밀번호 구조체 선언
{
	char id[6];
	char password[5];
	char Login_id[20];
	char Login_password[20];

};



int setLogin(); // 로그인 함수

#endif