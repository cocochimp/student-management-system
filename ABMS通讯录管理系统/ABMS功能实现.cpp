//函数定义

#include"ABMS.h"
#define max 1000

//联系人结构体
struct person {
	string m_name;
	int m_sex;    //1为男，2为女
	int m_age;
	string m_phone;
	string m_addr;
};

//通讯录结构体
struct addressbooks {
	struct person personArray[max];
	int m_size;      //通讯录人员个数
};

  //菜单界面
void showMenu() {
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}

//1、添加联系人
void addperson(addressbooks* abs) {
	if (abs->m_size == max) {
		cout << "通讯录已满，无法添加！" << endl;
		/*return;*/
	}
	else {
		string name;		//姓名
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_name=name;

		cout << "请输入性别：" << endl;		//性别
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		
		int sex = 0;
		while(true){
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}

		cout << "请输入年龄：" << endl;		//年龄
		int age = 0;
		while (true) {
			cin >> age;
			if (age <= 100 && age>=1) {
				abs->personArray[abs->m_size].m_age = age;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}

		string phone;		//电话
		cout << "请输入联系电话：" << endl;
		cin >> phone;
		abs->personArray[abs->m_size].m_phone = phone;

		string address;		//住址
		cout << "请输入家庭住址：" << endl;
		cin >> address;
		abs->personArray[abs->m_size].m_addr = address;

		//更新通讯录人数
		abs->m_size++;
		cout << "添加成功！" << endl;

		//清屏操作
		system("cls");
	}
}

//2、显示联系人
void showperson(addressbooks* abs) {
	//判断通讯录有没有人
	if (abs->m_size == 0) {
		cout << "当前的记录为空！" << endl;
	}
	else {
		for (int i = 0; i < abs->m_size; i++) {
			cout << "姓名：" << abs->personArray[i].m_name <<"\t\t";
			cout << "性别：" << (abs->personArray[i].m_sex ==1 ?"男":"女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_age << "\t\t";
			cout << "电话：" << abs->personArray[i].m_phone << "\t\t";
			cout << "地址：" << abs->personArray[i].m_addr << endl;
		}
	}
	system("pause");
	system("cls");
}

//3、删除联系人
  //判断此人是否存在
int isexist(addressbooks *abs,string name) {
	for (int i = 0; i < abs->m_size; i++) {
		if (abs->personArray[i].m_name == name) {
			return i;
		}
	}
	return -1;  //如果遍历都没找到，返回-1;
}
  //删除指定联系人
void deleteperson(addressbooks* abs) {
	cout << "请输入你要删除的联系人" << endl;

	string name;
	cin >> name;
	//ret ==-1,未查到
	int ret = isexist(abs, name);
	if (ret != -1) {
		for (int i = ret; i < abs->m_size; i++) {
			//数据前移
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_size--;
		cout << "删除成功！" << endl;
	}
	else {
		cout << "查无此人！" << endl;
	}

	system("pause");
	system("cls");
}

//4、查找指定联系人信息
void findperson(addressbooks* abs) {
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;

	//判断指定联系人是否在通讯录中
	int ret = isexist(abs, name);

	if (ret != -1) {
		cout << "姓名：" << abs->personArray[ret].m_name << "\t\t";
		cout << "性别：" << abs->personArray[ret].m_sex << "\t\t";
		cout << "年龄：" << abs->personArray[ret].m_age << "\t\t";
		cout << "电话：" << abs->personArray[ret].m_phone << "\t\t";
		cout << "住址：" << abs->personArray[ret].m_addr << "\t\t";
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//5、修改指定联系人信息
void modifyperson(addressbooks * abs) {
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;

	int ret = isexist(abs, name);

	if (ret != -1) {
		//姓名
		string name;
		cout << "请输入名字：" << endl;
		cin >> name;
		abs->personArray[ret].m_name = name;
		
		//性别
		cout << "请输入性别：" << endl;
		cout << "1 —— 男" << endl;
		cout << "2 —— 女" << endl;
		int sex = 0;

		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}

		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_age = age;

		//电话
		string phone;
		cout << "请输入联系电话：" << endl;
		cin >> phone;
		abs->personArray[ret].m_phone = phone;

		//住址
		string address;
		cout << "请输入家庭住址：" << endl;
		cin >> address;
		abs->personArray[ret].m_addr = address;

		cout << "修改成功！" << endl;
	}
	else {
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");
}

//6、清空所有联系人
void cleanperson(addressbooks* abs) {
	abs->m_size = 0;
	cout << "通讯录已清空！" << endl;
	system("pause");
	system("cls");
}

//主函数
int main() {
	//创建通讯录结构体变量
	addressbooks abs;
	//初始化通讯录中当前成员个数
	abs.m_size = 0;

	int select = 0;

	while (true) {
		//菜单调用
		showMenu();

		cin >> select;
		switch (select) {
		case 1:		//1、添加联系人
			addperson(&abs);  //利用地址传递，可以修饰实参
			break;
		case 2:		//2、显示联系人
			showperson(&abs);
			break;
		case 3:		//3、删除联系人
		/*{
			cout << "请输入删除联系人的姓名：" << endl;
			string name;
			cin >> name;

			if (isexist(&abs, name) == -1) {
				cout << "查无此人！" << endl;
			}
			else {
				cout << "找到此人！" << endl;
			}
		}*/
			deleteperson(&abs);
			break;
		case 4:		//4、查找联系人
			findperson(&abs);
			break;
		case 5:		//5、修改联系人
			modifyperson(&abs);
			break;
		case 6:		//6、清空联系人
			cleanperson(&abs);
			break;
		case 0:		//0、退出通讯录
			cout << "欢迎下次使用!" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
		system("pause");
	}
}
