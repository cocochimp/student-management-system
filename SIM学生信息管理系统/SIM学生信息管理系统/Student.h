#pragma once
#include<iostream>
#include<string>
using namespace std;

//ְ���������
class Student
{
public:
	int s_id;
	string s_name;
	string s_sex;

	//��ʾ������Ϣ
	virtual void showInfo() = 0;

};
