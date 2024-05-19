#pragma once
#include<iostream>
#include<string>
using namespace std;

//职工抽象基类
class Student
{
public:
	int s_id;
	string s_name;
	string s_sex;

	//显示个人信息
	virtual void showInfo() = 0;

};
