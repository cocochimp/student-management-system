#include<iostream>
using namespace std;
#include"Student.h"

#include<fstream>
#define FILENAME "empFile.txt"


class Manager
{private:
	//��¼�ļ��е���������
	int Num;

	//Ա�������ָ��
	Student** Array;

public:
	
	//���캯��
	Manager();

	//���ֲ˵�
	void showMenu();

	//0���˳�ϵͳ
	void exitSystem();

	//�����ļ�
	void save();

	//1������ѧ��
	void addStudent();

	//��������
	~Manager();

};