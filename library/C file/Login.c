// c����	�Լ� ����

#include "stdafx.h"



int setLogin()  // �α��� �Լ�
{

	struct Loginadmin* L1 = malloc(sizeof(struct Loginadmin)); //���� �޸� �Ҵ�
	
	strcpy(L1->id, "admin"); 
	strcpy(L1->password, "1234"); //���̵� , ��й�ȣ ����
	
	printf("*****���� ���� ���α׷�*****\n");
	printf("���̵�: ");

	scanf("%s", L1->Login_id); 	// ���̵� �Է�


	printf("��й�ȣ: ");

	scanf("%s" , L1->Login_password); //��й�ȣ �Է�



	if (!strcmp(L1->id, L1->Login_id) && !strcmp(L1->password, L1 -> Login_password)) //���̵� ��й�ȣ Ȯ��

	{
		printf("�α��� ����\n");
		return 1;  //��ġ�ϸ� 1�� ��ȯ
	
	}
	else
	{
		printf("�α��� ����\n");
		return 0; //��ġ���� ������ 0�� ��ȯ , ���α׷� ����
		
	}

	free(L1); //���� �޸� ��ü

}





