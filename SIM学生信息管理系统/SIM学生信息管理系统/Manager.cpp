#include "Manager.h"
#include"College.h"


Manager::Manager()
{
	//��ʼ������
	this->Num = 0;

	//��ʼ������ָ��
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


//��ʾ���ܱ�
void Manager::showMenu() {
	cout << "       ѧ����Ϣ����(SIM)ϵͳ�˵�:  " << endl<<endl;
	cout << "*****     0���˳�SIMϵͳ           *****   " << endl;
	cout << "*****     1�����ѧ��������Ϣ      *****   " << endl;
	cout << "*****     2�����ѧ���ɼ���Ϣ      *****   " << endl;
	cout << "*****     3��ɾ��ѧ����Ϣ          *****   " << endl;
	cout << "*****     4������ѧ����Ϣ          *****   " << endl;
	cout << "*****     5�����ѧ����Ϣ          *****   " << endl;
	cout << "*****     6��������㲢��λ        *****   " << endl;
	cout << "*****     7����ʾѧ����            *****   " << endl;
	cout << "*****     8���������ѧ����Ϣ      *****   " << endl<<endl;
};

//0���˳�����
void Manager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//1������ѧ��
void Manager::addStudent(){

	cout << "����������ְ�������� " << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0) {
		//�����¿ռ��С
		int newSize = this->Num + addNum;

		//�����¿ռ�
		Student** newSpace = new Student * [newSize];

		//��ԭ�ռ������ݴ�ŵ��¿ռ���
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

			cout << "��������Ҫ��ӵ�ѧ����Ϣ��" << endl;
			cout << "ѧ�ţ�" << endl;
			cin >> id;

			cout << "������" << endl;
			cin >> name;

			cout << "�Ա�" << endl;
			cin >> sex;

			Student* student = NULL;
			student = new College(id, name, sex);



			newSpace[this->Num + addNum] = student;
		}
		//�ͷ�ԭ�пռ�
		delete[] this->Array;

		////�����¿ռ��ָ��
		//this->Array = newSpace;

		//�����µĸ���
		this->Num = newSize;
	}

	//��ʾ��Ϣ
	cout << "�ɹ����"<<endl;

	////���浽�ļ���
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







