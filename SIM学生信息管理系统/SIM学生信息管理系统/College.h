#pragma once 
#include<iostream>
using namespace std;
#include "Student.h"

//员工类
class College :public Student
{
public:

	//构造函数
	College(int id, string name, string sex);

	//显示个人信息
	virtual void showInfo();


};
