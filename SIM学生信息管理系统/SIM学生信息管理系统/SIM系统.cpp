#include<iostream>
using namespace std;
#include "Manager.h"
#include"Student.h"
#include"College.h"

//void test()
//{
//	Student* student = NULL;
//	student = new College(1, "����", "��");
//	student->showInfo();
//	
//}

int main() {

	Manager sim;
	int import = 0;
	while (true)
	{
		//չʾ�˵�
		sim.showMenu();
		cout << "ѡ��������Ĺ���(�������):" << endl;
		cin >> import;

		switch (import)
		{
		case 0: //�˳�ϵͳ
			sim.exitSystem();
			break;
		case 1: //���ְ��
			sim.addStudent();
			break;
		case 2: //��ʾְ��
			break;
		case 3: //ɾ��ְ��
			break;
		case 4: //�޸�ְ��
			break;
		case 5: //����ְ��
			break;
		case 6: //����ְ��
			break;
		case 7: //����ļ�
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}