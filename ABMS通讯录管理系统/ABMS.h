//函数声明

#include<iostream>
#include<string>
using namespace std;

//联系人结构体
struct person;

//通讯录结构体
struct addressbooks;

//菜单界面
void showMenu();

//1、添加联系人
void addperson(addressbooks* abs);

//2、显示联系人
void showperson(addressbooks* abs);

//3、删除联系人
  //判断此人是否存在
int isexist(addressbooks* abs, string name);
  //删除指定联系人
void deleteperson(addressbooks* abs);

//4、查找指定联系人信息
void findperson(addressbooks* abs);

//5、修改指定联系人信息
void modifyperson(addressbooks* abs);

//6、清空所有联系人
void cleanperson(addressbooks* abs);

