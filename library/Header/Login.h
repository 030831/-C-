//h���� ����ü , ���� , �Լ�����

#pragma once

#ifndef _LOGIN_H_
#define _LOGIN_H_

struct Loginadmin //�α��� ���̵� , ��й�ȣ ����ü ����
{
	char id[6];
	char password[5];
	char Login_id[20];
	char Login_password[20];

};



int setLogin(); // �α��� �Լ�

#endif