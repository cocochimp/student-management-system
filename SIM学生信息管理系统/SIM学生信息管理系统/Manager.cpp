#include "Manager.h"
#include"College.h"


Manager::Manager()
{
	//初始化人数
	this->Num = 0;

	//初始化数组指针
	this->Array = NULL;
}


void Manager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);


	for (int i = 0; i < this->Num; i++)
	{
		ofs << this->Array[i]->s_id << " "
			<< this->Array[i]->s_name << " "
			<< this->Array[i]->s_sex << endl;
	}

	ofs.close();
}


//显示功能表
void Manager::showMenu() {
	cout << "       学生信息管理(SIM)系统菜单:  " << endl<<endl;
	cout << "*****     0、退出SIM系统           *****   " << endl;
	cout << "*****     1、添加学生基本信息      *****   " << endl;
	cout << "*****     2、添加学生成绩信息      *****   " << endl;
	cout << "*****     3、删除学生信息          *****   " << endl;
	cout << "*****     4、查找学生信息          *****   " << endl;
	cout << "*****     5、添加学生信息          *****   " << endl;
	cout << "*****     6、绩点计算并排位        *****   " << endl;
	cout << "*****     7、显示学生表            *****   " << endl;
	cout << "*****     8、清空所有学生信息      *****   " << endl<<endl;
};

//0、退出操作
void Manager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//1、增加学生
void Manager::addStudent(){

	cout << "请输入增加职工数量： " << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0) {
		//计算新空间大小
		int newSize = this->Num + addNum;

		//开辟新空间
		Student** newSpace = new Student * [newSize];

		//将原空间下内容存放到新空间下
		if (this->Array != NULL)
		{
			for (int i = 0; i < this->Num; i++)
			{
				newSpace[i] = this->Array[i];
			}
		}

		for (int i = 0; i < addNum; i++) {
			int id;
			string name, sex;

			cout << "请输入你要添加的学生信息：" << endl;
			cout << "学号：" << endl;
			cin >> id;

			cout << "姓名：" << endl;
			cin >> name;

			cout << "性别：" << endl;
			cin >> sex;

			Student* student = NULL;
			student = new College(id, name, sex);



			newSpace[this->Num + addNum] = student;
		}
		//释放原有空间
		delete[] this->Array;

		////更改新空间的指向
		//this->Array = newSpace;

		//更新新的个数
		this->Num = newSize;
	}

	//提示信息
	cout << "成功添加"<<endl;

	////保存到文件中
	this->save();

	system("pause");
	system("cls");

	}




Manager::~Manager()
{
	if (this->Array != NULL)
	{
		delete[] this->Array;
	}
}







