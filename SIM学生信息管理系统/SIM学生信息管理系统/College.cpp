#include "College.h"

College::College(int id, string name, string sex)
{
	this->s_id = id;
	this->s_name = name;
	this->s_sex = sex;
}

void College::showInfo()
{
	cout << "ѧ����Ϣ��"<<endl;
	cout << "ѧ�ţ� " << this->s_id
		<< " \t������ " << this->s_name
		<< "    �Ա�" << this->s_sex << endl;
}



