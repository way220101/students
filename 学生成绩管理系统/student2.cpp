#pragma once
#include<string>
#include<iostream>
using namespace std;
#include"student2.h"
student2::student2() {
	//���ļ�������
	ifstream ifs;
	ifs.open("student.txt", ios::in);
	int num = this->get_EmpNum();
	this->m_EmpNum = num;
	//���ٿռ䣬���ļ��е����ݴ浽����
	this->m_EmpArray = new student * [this->m_EmpNum];
	this->init_Emp();

}
void student2::menu() {
	cout << "*******************************************************" << endl;
	cout << "********************��ӭʹ��ѧ������ϵͳ***************" << endl;
	cout << "********************��ѡ��-------**********************" << endl;
	cout << "********************1.����ѧ����Ϣ*********************" << endl;
	cout << "********************2.��ʾѧ����Ϣ*********************" << endl;
	cout << "********************3.ɾ��ѧ����Ϣ*********************" << endl;
	cout << "********************4.�޸�ѧ����Ϣ*********************" << endl;
	cout << "********************5.����ѧ����Ϣ*********************" << endl;
	cout << "********************6.��ѧ����ʾѧ����Ϣ***************" << endl;
	cout << "********************7.����ĵ�*************************" << endl;
	cout << "********************8.�鿴ѧ������*********************" << endl;
	cout << "********************9.�鿴ѧ�����Ƴɼ�*****************" << endl;
	cout << "********************10.���ճɼ�����********************" << endl;
	cout << "********************11.�鿴���������ͷ�**************" << endl;
	cout << "********************0.�˳�ϵͳ*************************" << endl;
	cout << "*******************************************************" << endl;
}
void student2::Add_Emp() {
	cout << "��ѡ�����ѧ��������" << endl;
	int addNum;
	cin >> addNum;
	if (addNum > 0) {
		int newSize = this->m_EmpNum + addNum;//������ӿռ��С
		student** newSpace = new student * [newSize];//�����¿ռ�
		if (this->m_EmpNum != 0) {//��ԭ�������ݿ������¿ռ�
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		for (int i = 0; i < addNum; i++) {
			int id;//ѧ��
			string name;//����
			int c;//�༶
			float Chinese;//���ĳɼ�
			float math;//��ѧ�ɼ�
			float English;//Ӣ��ɼ�
			cout << "������� " << i + 1 << "��ѧ����ѧ��" << endl;
			cin >> id;
			cout << "������� " << i + 1 << "��ѧ���İ༶" << endl;
			cin >> c;
			cout << "������� " << i + 1 << "��ѧ��������" << endl;
			cin >> name;
			cout << "������� " << i + 1 << "��ѧ�������ĳɼ�" << endl;
			cin >> Chinese;
			cout << "������� " << i + 1 << "��ѧ������ѧ�ɼ�" << endl;
			cin >> math;
			cout << "������� " << i + 1 << "��ѧ����Ӣ��ɼ�" << endl;
			cin >> English;
			student* st = NULL;
			switch (c) {
			case 1:
				st = new class1stu(id, name, c, Chinese, math, English);
				break;
			case 2:
				st = new class2stu(id, name, c, Chinese, math, English);
				break;
			case 3:
				st = new class3stu(id, name, c, Chinese, math, English);
				break;
			case 4:
				st = new class4stu(id, name, c, Chinese, math, English);
				break;
			case 5:
				st = new class5stu(id, name, c, Chinese, math, English);
				break;
			}

			newSpace[this->m_EmpNum + i] = st;//��������ѧ�����浽����

		}

		delete[]this->m_EmpArray;//�ͷ�ԭ�ռ�
		this->m_EmpArray = newSpace;//�����¿ռ�ָ��
		this->m_EmpNum = newSize;//��ѧ������
		cout << "�ɹ����" << addNum << "��ѧ��" << endl;
		this->save();

	}
	else {
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");

}
void student2::save() {
	ofstream ofs;
	ofs.open("student.txt", ios::out);//д�ļ�
	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs <<this->m_EmpArray[i]->id << "       "
			 << this->m_EmpArray[i]->name << "       "
			 << this->m_EmpArray[i]->c << "       "
			<< this->m_EmpArray[i]->Chinese << "       "
			<< this->m_EmpArray[i]->math << "       "
			<< this->m_EmpArray[i]->English << "       " << endl;
	}
	ofs.close();
}//����д���ĵ�		//b
int student2::get_EmpNum() {
	ifstream ifs;
	ifs.open("student.txt", ios::in);//���ļ�
	int id;
	string name;
	int c;
	float Chinese;
	float math;
	float English;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> c && ifs >> Chinese && ifs >> math && ifs >> English) {
		num++;

	}
	return num;
}
void student2::init_Emp() {
	ifstream ifs;
	ifs.open("student.txt", ios::in);
	int id;
	string name;
	int c;
	float Chinese;
	float math;
	float English;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> c && ifs >> Chinese && ifs >> math && ifs >> English) {
		student* st = NULL;
		if (c == 1) {
			st = new class1stu(id, name, c, Chinese, math, English);
		}
		if (c == 2) {
			st = new class2stu(id, name, c, Chinese, math, English);
		}
		if (c == 3) {
			st = new class3stu(id, name, c, Chinese, math, English);
		}
		if (c == 4) {
			st = new class4stu(id, name, c, Chinese, math, English);
		}
		if (c == 5) {
			st = new class5stu(id, name, c, Chinese, math, English);
		}
		this->m_EmpArray[index] = st;
		index++;
	}
	ifs.close();
}
void student2::show_Emp() {
	for (int i = 0; i <this->m_EmpNum; i++) {
		this->m_EmpArray[i]->show();
	}
	system("pause");
	system("cls");
}
void student2::Del_Emp() {
	cout << "������Ҫɾ����ѧ��ѧ��" << endl;
	int id = 0;
	cin >> id;
	int index = this->IsExist(id);
	if (index != -1) {
		cout << "�ҵ���ͬѧ,ȷ��ɾ����" << endl;
		cout << "1.ȷ��" << endl << "2.����" << endl;
		int a=0;
		cin >> a;
		if (a == 1) {
			for (int i = index; i < this->m_EmpNum - 1; i++) {
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];//����ǰ��
			}
			this->m_EmpNum--;
			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
	}
	else {
		cout << "ʧ�ܣ�δ�ҵ���ѧ��" << endl;
	}
	system("pause");
	system("cls");
}
int student2::IsExist(int id) {
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->id == id) {
			cout << "�ҵ�����" << endl;
			index = i;
			break;
		}
		if (i == this->m_EmpNum - 1) {
			cout << "���޴���" << endl;
		}
	}
				return index;
}
void student2::Mod_Epm() {
	cout << "��������Ҫ�޸�ѧ����ѧ��" << endl;
	int a = 0;
	cin >> a;
	int b=this->IsExist(a);
	if (b != -1) {
		cout << "�ҵ���ѧ��" << endl;
		delete this->m_EmpArray[b];
		int newId = 0;
		string name = "";
		int c = 0;
		float Chinese = 0;
		float math = 0;
		float English = 0;
		cout << "ԭ��ѧ��Ϊ��" << a << endl << "�޸�Ϊ��";
		cin >> newId;
		cout << "������������";
		cin >> name;
		cout << endl;
		cout << "������༶";
		cin >> c;
		cout << endl;
		cout << "���������ĳɼ���";
		cin >> Chinese;
		cout << endl;
		cout << "��������ѧ�ɼ���";
		cin >> math;
		cout << endl;
		cout << "������Ӣ��ɼ���";
		cin >> English;
		cout << endl;
		student* st = NULL;
		switch (c) {
		case 1:
			st = new class1stu(newId, name, c, Chinese, math, English);
			break;
		case 2:
			st = new class2stu(newId, name, c, Chinese, math, English);
		case 3:
			st = new class3stu(newId, name, c, Chinese, math, English);
		case 4:
			st = new class4stu(newId, name, c, Chinese, math, English);
			break;
		case 5:
			st = new class5stu(newId, name, c, Chinese, math, English);
			break;
		default:
			break;
		}
		//��������
		this->m_EmpArray[b] = st;
		cout << "�޸ĳɹ�" << endl;
		//���浽�ļ���
		this->save();
	}
	else {
		cout << "δ�ҵ���ѧ��" << endl;
	}
	system("pause");
	system("cls");
}
void student2::Find_Emp() {
	cout << "��������ҷ�ʽ��" << endl;
	cout << "1.����ѧ�Ų���" << endl;
	cout << "2.������������" << endl;
	int s = 0;
	cin >> s;
	switch (s) {
	case 1: {
		cout << "��������Ҫ�ҵ�ѧ����ѧ�ţ�" << endl;
		int id = 0;
		cin >> id;
		bool flag = false;
		for (int i = 0; i < this->m_EmpNum; i++) {
			if (this->m_EmpArray[i]->id == id) {
				cout << "�ҵ�����" << endl;
				cout << "ѧ��Ϊ��" << this->m_EmpArray[i]->id
					<< "  ����Ϊ�� " << this->m_EmpArray[i]->name
					<< "  �༶Ϊ�� " << this->m_EmpArray[i]->c
					<< "  ���ģ� " << this->m_EmpArray[i]->Chinese
					<< "  ��ѧ�� " << this->m_EmpArray[i]->math
					<< "  Ӣ� " << this->m_EmpArray[i]->English
					<< endl;
				flag = true;
			}
		} 
		if (flag == false) {
			cout << "����ʧ�ܲ��޴���" << endl;
		}
		break;
	}
	case 2: {
		cout << "��������Ҫ�ҵ�ѧ��������" << endl;
		string nname = "";
		cin >> nname;
		bool flag = false;
		for (int i = 0; i < this->m_EmpNum; i++) {
			if (this->m_EmpArray[i]->name == nname) {
				cout << "�ҵ�����" << endl;
				cout << "ѧ��Ϊ��" << this->m_EmpArray[i]->id
					<< "  ����Ϊ�� " << this->m_EmpArray[i]->name
					<< "  �༶Ϊ�� " << this->m_EmpArray[i]->c
					<< "  ���ģ� " << this->m_EmpArray[i]->Chinese
					<< "  ��ѧ�� " << this->m_EmpArray[i]->math
					<< "  Ӣ� " << this->m_EmpArray[i]->English
					<< endl;
				flag= true;
			}
		}
		if (flag == false) {
			cout << "����ʧ�ܲ��޴���" << endl;
		}

		break;
	}
	default:
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");
}
void student2::sort_emp() {
	cout << "���ճɼ��ܷ�����" << endl;
	for (int i = 0; i < this->m_EmpNum; i++) {
		int min = i;
		for (int j = i + 1; j < this->m_EmpNum; j++) {
			if (this->m_EmpArray[min]->Chinese + this->m_EmpArray[min]->math + this->m_EmpArray[min]->English < this->m_EmpArray[j]->Chinese + this->m_EmpArray[j]->math + this->m_EmpArray[j]->English)
			{
				min = j;
			}
		}
		if (i != min) {
			student* temp = this->m_EmpArray[i];
			this->m_EmpArray[i] = this->m_EmpArray[min];
			this->m_EmpArray[min] = temp;
		}
	}
	for (int i = 0; i < this->m_EmpNum; i++) {
		this->m_EmpArray[i]->show();
		float a = this->m_EmpArray[i]->Chinese + this->m_EmpArray[i]->math + this->m_EmpArray[i]->English;
		cout << "�ܷ�Ϊ��" << a << "  ����Ϊ��" << i + 1 << "��" << endl;
		cout << endl;
		cout << endl;
	}
	system("pause");
	system("cls");
}
void student2::Sort_Emp() {
	cout << "����ѧ�Ž�������" << endl;
	for (int i = 0; i < this->m_EmpNum; i++) {
		int min = i;
		for (int j = i + 1; j < this->m_EmpNum; j++) {
			if (this->m_EmpArray[min]->id>this->m_EmpArray[j]->id) {
				min = j;
			}
		}

		if (i != min) {
			student* temp = this->m_EmpArray[i];
			this->m_EmpArray[i] = this->m_EmpArray[min];
			this->m_EmpArray[min] = temp;
		}
	}
	this->show_Emp();
}
void student2::Clean_File() {
	cout << "ȷ������ļ���" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
	int s=0;
	cin >> s;
	switch (s) {
	case 1: {
		ofstream ofs("student.txt", ios::trunc);
		ofs.close();
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				if (this->m_EmpArray[i] != NULL) {
					delete[]this->m_EmpArray[i];
				}
			}
			this->m_EmpNum = 0;
			delete[]this->m_EmpArray;
			this->m_EmpArray = NULL;
		}
		cout << "��ճɹ�!" << endl;
		break;
	}
	case 2:
		system("pause");
		system("cls");

	}
	system("pause");
	system("cls");
}
void student2::danke() {
	cout << "��������Ҫ�ҵ��˵�����" << endl;
	string name = "";
	cin >> name;
	int index = this->Isexist(name);
	if (index ==-1) {
		cout << "δ�ҵ�����"<<endl;
	}
	else {
		cout << "��������Ҫ�ҵĿ�Ŀ����" << endl;
		cout << "1.����" << endl
			<< "2.��ѧ" << endl
			<< "3.Ӣ��" << endl
			<< "4.ƽ����" << endl;
		int k = 0;
		cin >> k;
		float a = 0;
		switch (k) {
		case 1:
			cout << "���ĳɼ�Ϊ��" << this->m_EmpArray[index]->Chinese<<endl;
			break;
		case 2:
			cout << "��ѧ�ɼ�Ϊ��" << this->m_EmpArray[index]->math<<endl;
			break;
		case 3:
			cout << "Ӣ��ɼ�Ϊ��" << this->m_EmpArray[index]->English<<endl;
			break;
		case 4:
			a = a / 3;
			cout << "ƽ����Ϊ��" << a << endl;
		default:
			a = this->m_EmpArray[index]->Chinese + this->m_EmpArray[index]->math + this->m_EmpArray[index]->English;
			cout << "�ܷ�Ϊ��" << a << endl;
			break;
		}
	}
	system("pause");
	system("cls");
}
int student2::Isexist(string name){
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->name == name) {
			index = i;
			break;
		}
	}
	return index;
}
void student2::find() {
	int Chinesemin = 150;
	int Chinesemax = 0;
	int mathmin = 150;
	int mathmax = 0;
	int englishmin = 150;
	int englishmax = 0;
	cout << "������Ҫ�ҵ�����" << endl;
	cout << "1.��߷�" << endl;
	cout << "2.��ͷ�" << endl;
	int a = 0;
	cin >> a;
	cout << "������Ҫ�ҷ����Ŀ�Ŀ��" << endl;
	cout << "1.����" << endl;
	cout << "2.��ѧ" << endl;
	cout << "3.Ӣ��" << endl;
	int b = 0;
	cin >> b;
	if (a == 1 && b == 1) {
		int j = 0;
		for (int i = 0; i < this->m_EmpNum; i++) {
			if (this->m_EmpArray[i]->Chinese > Chinesemax) {
				Chinesemax = this->m_EmpArray[i]->Chinese;
				j = i;
			}
		}
		cout << "ѧ�ţ�" << this->m_EmpArray[j]->id;
		cout << "  ����Ϊ��" << this->m_EmpArray[j]->name;
		cout <<"  ���ĳɼ�Ϊ��" << this->m_EmpArray[j]->Chinese << endl;
	}
	if (a == 1 && b == 2) {
		int j = 0;
		for (int i = 0; i < this->m_EmpNum; i++) {
			if (this->m_EmpArray[i]->math > mathmax ) {
				mathmax = this->m_EmpArray[i]->math;
				j = i;
			}
		}
		cout << "ѧ�ţ�" << this->m_EmpArray[j]->id;
		cout << "  ����Ϊ��" << this->m_EmpArray[j]->name;
		cout << "  ��ѧ�ɼ�Ϊ��" << this->m_EmpArray[j]->math << endl;
	}
	if (a == 1 && b == 3) {
		int j = 0;
		for (int i = 0; i < this->m_EmpNum; i++) {
			if (this->m_EmpArray[i]->English > englishmax ) {
				englishmax = this->m_EmpArray[i]->English;
				j = i;
			}
		}
		cout << "ѧ�ţ�" << this->m_EmpArray[j]->id;
		cout << "  ����Ϊ��" << this->m_EmpArray[j]->name;
		cout << "  Ӣ��ɼ�Ϊ��" << this->m_EmpArray[j]->English << endl;
	}
	if (a == 2 && b == 1) {
		int j = 0;
		for (int i = 0; i < this->m_EmpNum; i++) {
			if (this->m_EmpArray[i]->Chinese<Chinesemin) {
				Chinesemin = this->m_EmpArray[i]->Chinese;
				j = i;
			}
		}
		cout << "ѧ�ţ�" << this->m_EmpArray[j]->id;
		cout << "  ����Ϊ��" << this->m_EmpArray[j]->name;
		cout << "  ���ĳɼ�Ϊ��" << this->m_EmpArray[j]->Chinese << endl;
	}
	if (a == 2 && b == 3) {
		int j = 0;
		for (int i = 0; i < this->m_EmpNum; i++) {
			if (this->m_EmpArray[i]->English < englishmin) {
				englishmin = this->m_EmpArray[i]->English;
				j = i;
			}
		}
		cout << "ѧ�ţ�" << this->m_EmpArray[j]->id;
		cout << "  ����Ϊ��" << this->m_EmpArray[j]->name;
		cout << "  Ӣ��ɼ�Ϊ��" << this->m_EmpArray[j]->English << endl;
	}
	if (a == 2 && b == 2) {
		int j = 0;
		for (int i = 0; i < this->m_EmpNum; i++) {
			if (this->m_EmpArray[i]->math < mathmin) {
				mathmin = this->m_EmpArray[i]->math;
				j = i;
			}
		}
		cout << "ѧ�ţ�" << this->m_EmpArray[j]->id;
		cout << "  ����Ϊ��" << this->m_EmpArray[j]->name;
		cout << "  ��ѧ�ɼ�Ϊ��" << this->m_EmpArray[j]->math << endl;
	}
	system("pause");
	system("cls");
}