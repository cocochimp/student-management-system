//��������

#include"ABMS.h"
#define max 1000

//��ϵ�˽ṹ��
struct person {
	string m_name;
	int m_sex;    //1Ϊ�У�2ΪŮ
	int m_age;
	string m_phone;
	string m_addr;
};

//ͨѶ¼�ṹ��
struct addressbooks {
	struct person personArray[max];
	int m_size;      //ͨѶ¼��Ա����
};

  //�˵�����
void showMenu() {
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}

//1�������ϵ��
void addperson(addressbooks* abs) {
	if (abs->m_size == max) {
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		/*return;*/
	}
	else {
		string name;		//����
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_name=name;

		cout << "�������Ա�" << endl;		//�Ա�
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		
		int sex = 0;
		while(true){
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "�����������������룡" << endl;
		}

		cout << "���������䣺" << endl;		//����
		int age = 0;
		while (true) {
			cin >> age;
			if (age <= 100 && age>=1) {
				abs->personArray[abs->m_size].m_age = age;
				break;
			}
			cout << "�����������������룡" << endl;
		}

		string phone;		//�绰
		cout << "��������ϵ�绰��" << endl;
		cin >> phone;
		abs->personArray[abs->m_size].m_phone = phone;

		string address;		//סַ
		cout << "�������ͥסַ��" << endl;
		cin >> address;
		abs->personArray[abs->m_size].m_addr = address;

		//����ͨѶ¼����
		abs->m_size++;
		cout << "��ӳɹ���" << endl;

		//��������
		system("cls");
	}
}

//2����ʾ��ϵ��
void showperson(addressbooks* abs) {
	//�ж�ͨѶ¼��û����
	if (abs->m_size == 0) {
		cout << "��ǰ�ļ�¼Ϊ�գ�" << endl;
	}
	else {
		for (int i = 0; i < abs->m_size; i++) {
			cout << "������" << abs->personArray[i].m_name <<"\t\t";
			cout << "�Ա�" << (abs->personArray[i].m_sex ==1 ?"��":"Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].m_age << "\t\t";
			cout << "�绰��" << abs->personArray[i].m_phone << "\t\t";
			cout << "��ַ��" << abs->personArray[i].m_addr << endl;
		}
	}
	system("pause");
	system("cls");
}

//3��ɾ����ϵ��
  //�жϴ����Ƿ����
int isexist(addressbooks *abs,string name) {
	for (int i = 0; i < abs->m_size; i++) {
		if (abs->personArray[i].m_name == name) {
			return i;
		}
	}
	return -1;  //���������û�ҵ�������-1;
}
  //ɾ��ָ����ϵ��
void deleteperson(addressbooks* abs) {
	cout << "��������Ҫɾ������ϵ��" << endl;

	string name;
	cin >> name;
	//ret ==-1,δ�鵽
	int ret = isexist(abs, name);
	if (ret != -1) {
		for (int i = ret; i < abs->m_size; i++) {
			//����ǰ��
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_size--;
		cout << "ɾ���ɹ���" << endl;
	}
	else {
		cout << "���޴��ˣ�" << endl;
	}

	system("pause");
	system("cls");
}

//4������ָ����ϵ����Ϣ
void findperson(addressbooks* abs) {
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;

	//�ж�ָ����ϵ���Ƿ���ͨѶ¼��
	int ret = isexist(abs, name);

	if (ret != -1) {
		cout << "������" << abs->personArray[ret].m_name << "\t\t";
		cout << "�Ա�" << abs->personArray[ret].m_sex << "\t\t";
		cout << "���䣺" << abs->personArray[ret].m_age << "\t\t";
		cout << "�绰��" << abs->personArray[ret].m_phone << "\t\t";
		cout << "סַ��" << abs->personArray[ret].m_addr << "\t\t";
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//5���޸�ָ����ϵ����Ϣ
void modifyperson(addressbooks * abs) {
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;

	int ret = isexist(abs, name);

	if (ret != -1) {
		//����
		string name;
		cout << "���������֣�" << endl;
		cin >> name;
		abs->personArray[ret].m_name = name;
		
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1 ���� ��" << endl;
		cout << "2 ���� Ů" << endl;
		int sex = 0;

		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}

		//����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_age = age;

		//�绰
		string phone;
		cout << "��������ϵ�绰��" << endl;
		cin >> phone;
		abs->personArray[ret].m_phone = phone;

		//סַ
		string address;
		cout << "�������ͥסַ��" << endl;
		cin >> address;
		abs->personArray[ret].m_addr = address;

		cout << "�޸ĳɹ���" << endl;
	}
	else {
		cout << "���޴��ˣ�" << endl;
	}
	system("pause");
	system("cls");
}

//6�����������ϵ��
void cleanperson(addressbooks* abs) {
	abs->m_size = 0;
	cout << "ͨѶ¼����գ�" << endl;
	system("pause");
	system("cls");
}

//������
int main() {
	//����ͨѶ¼�ṹ�����
	addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_size = 0;

	int select = 0;

	while (true) {
		//�˵�����
		showMenu();

		cin >> select;
		switch (select) {
		case 1:		//1�������ϵ��
			addperson(&abs);  //���õ�ַ���ݣ���������ʵ��
			break;
		case 2:		//2����ʾ��ϵ��
			showperson(&abs);
			break;
		case 3:		//3��ɾ����ϵ��
		/*{
			cout << "������ɾ����ϵ�˵�������" << endl;
			string name;
			cin >> name;

			if (isexist(&abs, name) == -1) {
				cout << "���޴��ˣ�" << endl;
			}
			else {
				cout << "�ҵ����ˣ�" << endl;
			}
		}*/
			deleteperson(&abs);
			break;
		case 4:		//4��������ϵ��
			findperson(&abs);
			break;
		case 5:		//5���޸���ϵ��
			modifyperson(&abs);
			break;
		case 6:		//6�������ϵ��
			cleanperson(&abs);
			break;
		case 0:		//0���˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��!" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
		system("pause");
	}
}
