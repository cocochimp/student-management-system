#include<iostream>
using namespace std;
#include "Manager.h"
#include"Student.h"
#include"College.h"

//void test()
//{
//	Student* student = NULL;
//	student = new College(1, "张三", "男");
//	student->showInfo();
//	
//}

int main() {

	Manager sim;
	int import = 0;
	while (true)
	{
		//展示菜单
		sim.showMenu();
		cout << "选择你所需的功能(输入序号):" << endl;
		cin >> import;

		switch (import)
		{
		case 0: //退出系统
			sim.exitSystem();
			break;
		case 1: //添加职工
			sim.addStudent();
			break;
		case 2: //显示职工
			break;
		case 3: //删除职工
			break;
		case 4: //修改职工
			break;
		case 5: //查找职工
			break;
		case 6: //排序职工
			break;
		case 7: //清空文件
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}