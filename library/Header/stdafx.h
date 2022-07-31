#pragma once  //헤더파일 중복 방지

#ifndef _STDAFX_H_// 조건부 컴파일 매크로가 정의되어 있을 때만 코드를 컴파일
#define _STDAFX_H_ //매크로 선언

#define _CRT_SECURE_NO_WARNINGS //scanf 오류 방지


#include <stdio.h>
#include <string.h>
#include <stdlib.h> // malloc , free

#include "Login.h"  // 초기 로그인 헤더 파잏
#include "screen.h" // 메뉴 출력 헤더 파일
#include "books.h" // 책 대출 , 반납 헤더 파일

#endif