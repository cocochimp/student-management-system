//��������

#include<iostream>
#include<string>
using namespace std;

//��ϵ�˽ṹ��
struct person;

//ͨѶ¼�ṹ��
struct addressbooks;

//�˵�����
void showMenu();

//1�������ϵ��
void addperson(addressbooks* abs);

//2����ʾ��ϵ��
void showperson(addressbooks* abs);

//3��ɾ����ϵ��
  //�жϴ����Ƿ����
int isexist(addressbooks* abs, string name);
  //ɾ��ָ����ϵ��
void deleteperson(addressbooks* abs);

//4������ָ����ϵ����Ϣ
void findperson(addressbooks* abs);

//5���޸�ָ����ϵ����Ϣ
void modifyperson(addressbooks* abs);

//6�����������ϵ��
void cleanperson(addressbooks* abs);

