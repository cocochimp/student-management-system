#include<iostream>
using namespace std;
#include"Student.h"

#include<fstream>
#define FILENAME "empFile.txt"


class Manager
{private:
	//记录文件中的人数个数
	int Num;

	//员工数组的指针
	Student** Array;

public:
	
	//构造函数
	Manager();

	//呈现菜单
	void showMenu();

	//0、退出系统
	void exitSystem();

	//保存文件
	void save();

	//1、增加学生
	void addStudent();

	//析构函数
	~Manager();

};