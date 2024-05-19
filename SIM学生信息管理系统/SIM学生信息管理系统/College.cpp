#include "College.h"

College::College(int id, string name, string sex)
{
	this->s_id = id;
	this->s_name = name;
	this->s_sex = sex;
}

void College::showInfo()
{
	cout << "学生信息："<<endl;
	cout << "学号： " << this->s_id
		<< " \t姓名： " << this->s_name
		<< "    性别：" << this->s_sex << endl;
}



