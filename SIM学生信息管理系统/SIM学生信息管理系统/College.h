#pragma once 
#include<iostream>
using namespace std;
#include "Student.h"

//Ա����
class College :public Student
{
public:

	//���캯��
	College(int id, string name, string sex);

	//��ʾ������Ϣ
	virtual void showInfo();


};
