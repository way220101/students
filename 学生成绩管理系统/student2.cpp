#pragma once
#include<string>
#include<iostream>
using namespace std;
#include"student2.h"
student2::student2() {
	//当文件不存在
	ifstream ifs;
	ifs.open("student.txt", ios::in);
	int num = this->get_EmpNum();
	this->m_EmpNum = num;
	//开辟空间，将文件中的数据存到数组
	this->m_EmpArray = new student * [this->m_EmpNum];
	this->init_Emp();

}
void student2::menu() {
	cout << "*******************************************************" << endl;
	cout << "********************欢迎使用学生管理系统***************" << endl;
	cout << "********************请选择-------**********************" << endl;
	cout << "********************1.增加学生信息*********************" << endl;
	cout << "********************2.显示学生信息*********************" << endl;
	cout << "********************3.删除学生信息*********************" << endl;
	cout << "********************4.修改学生信息*********************" << endl;
	cout << "********************5.查找学生信息*********************" << endl;
	cout << "********************6.按学号显示学生信息***************" << endl;
	cout << "********************7.清空文档*************************" << endl;
	cout << "********************8.查看学生总数*********************" << endl;
	cout << "********************9.查看学生单科成绩*****************" << endl;
	cout << "********************10.按照成绩排名********************" << endl;
	cout << "********************11.查看单科最高最低分**************" << endl;
	cout << "********************0.退出系统*************************" << endl;
	cout << "*******************************************************" << endl;
}
void student2::Add_Emp() {
	cout << "请选择添加学生的人数" << endl;
	int addNum;
	cin >> addNum;
	if (addNum > 0) {
		int newSize = this->m_EmpNum + addNum;//计算添加空间大小
		student** newSpace = new student * [newSize];//开辟新空间
		if (this->m_EmpNum != 0) {//将原来的内容拷贝到新空间
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		for (int i = 0; i < addNum; i++) {
			int id;//学号
			string name;//姓名
			int c;//班级
			float Chinese;//语文成绩
			float math;//数学成绩
			float English;//英语成绩
			cout << "请输入第 " << i + 1 << "个学生的学号" << endl;
			cin >> id;
			cout << "请输入第 " << i + 1 << "个学生的班级" << endl;
			cin >> c;
			cout << "请输入第 " << i + 1 << "个学生的姓名" << endl;
			cin >> name;
			cout << "请输入第 " << i + 1 << "个学生的语文成绩" << endl;
			cin >> Chinese;
			cout << "请输入第 " << i + 1 << "个学生的数学成绩" << endl;
			cin >> math;
			cout << "请输入第 " << i + 1 << "个学生的英语成绩" << endl;
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

			newSpace[this->m_EmpNum + i] = st;//将创建的学生保存到数组

		}

		delete[]this->m_EmpArray;//释放原空间
		this->m_EmpArray = newSpace;//更改新空间指向
		this->m_EmpNum = newSize;//新学生人数
		cout << "成功添加" << addNum << "个学生" << endl;
		this->save();

	}
	else {
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");

}
void student2::save() {
	ofstream ofs;
	ofs.open("student.txt", ios::out);//写文件
	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs <<this->m_EmpArray[i]->id << "       "
			 << this->m_EmpArray[i]->name << "       "
			 << this->m_EmpArray[i]->c << "       "
			<< this->m_EmpArray[i]->Chinese << "       "
			<< this->m_EmpArray[i]->math << "       "
			<< this->m_EmpArray[i]->English << "       " << endl;
	}
	ofs.close();
}//保存写入文档		//b
int student2::get_EmpNum() {
	ifstream ifs;
	ifs.open("student.txt", ios::in);//读文件
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
	cout << "请输入要删除的学生学号" << endl;
	int id = 0;
	cin >> id;
	int index = this->IsExist(id);
	if (index != -1) {
		cout << "找到该同学,确定删除吗？" << endl;
		cout << "1.确定" << endl << "2.返回" << endl;
		int a=0;
		cin >> a;
		if (a == 1) {
			for (int i = index; i < this->m_EmpNum - 1; i++) {
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];//数据前移
			}
			this->m_EmpNum--;
			this->save();
			cout << "删除成功" << endl;
		}
	}
	else {
		cout << "失败，未找到该学生" << endl;
	}
	system("pause");
	system("cls");
}
int student2::IsExist(int id) {
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->id == id) {
			cout << "找到此人" << endl;
			index = i;
			break;
		}
		if (i == this->m_EmpNum - 1) {
			cout << "查无此人" << endl;
		}
	}
				return index;
}
void student2::Mod_Epm() {
	cout << "请输入您要修改学生的学号" << endl;
	int a = 0;
	cin >> a;
	int b=this->IsExist(a);
	if (b != -1) {
		cout << "找到该学生" << endl;
		delete this->m_EmpArray[b];
		int newId = 0;
		string name = "";
		int c = 0;
		float Chinese = 0;
		float math = 0;
		float English = 0;
		cout << "原来学号为：" << a << endl << "修改为：";
		cin >> newId;
		cout << "请输入姓名：";
		cin >> name;
		cout << endl;
		cout << "请输入班级";
		cin >> c;
		cout << endl;
		cout << "请输入语文成绩：";
		cin >> Chinese;
		cout << endl;
		cout << "请输入数学成绩：";
		cin >> math;
		cout << endl;
		cout << "请输入英语成绩：";
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
		//更新数据
		this->m_EmpArray[b] = st;
		cout << "修改成功" << endl;
		//保存到文件中
		this->save();
	}
	else {
		cout << "未找到该学生" << endl;
	}
	system("pause");
	system("cls");
}
void student2::Find_Emp() {
	cout << "请输入查找方式：" << endl;
	cout << "1.按照学号查找" << endl;
	cout << "2.按照姓名查找" << endl;
	int s = 0;
	cin >> s;
	switch (s) {
	case 1: {
		cout << "请输入你要找的学生的学号：" << endl;
		int id = 0;
		cin >> id;
		bool flag = false;
		for (int i = 0; i < this->m_EmpNum; i++) {
			if (this->m_EmpArray[i]->id == id) {
				cout << "找到此人" << endl;
				cout << "学号为：" << this->m_EmpArray[i]->id
					<< "  姓名为： " << this->m_EmpArray[i]->name
					<< "  班级为： " << this->m_EmpArray[i]->c
					<< "  语文： " << this->m_EmpArray[i]->Chinese
					<< "  数学： " << this->m_EmpArray[i]->math
					<< "  英语： " << this->m_EmpArray[i]->English
					<< endl;
				flag = true;
			}
		} 
		if (flag == false) {
			cout << "查找失败查无此人" << endl;
		}
		break;
	}
	case 2: {
		cout << "请输入你要找的学生的姓名" << endl;
		string nname = "";
		cin >> nname;
		bool flag = false;
		for (int i = 0; i < this->m_EmpNum; i++) {
			if (this->m_EmpArray[i]->name == nname) {
				cout << "找到此人" << endl;
				cout << "学号为：" << this->m_EmpArray[i]->id
					<< "  姓名为： " << this->m_EmpArray[i]->name
					<< "  班级为： " << this->m_EmpArray[i]->c
					<< "  语文： " << this->m_EmpArray[i]->Chinese
					<< "  数学： " << this->m_EmpArray[i]->math
					<< "  英语： " << this->m_EmpArray[i]->English
					<< endl;
				flag= true;
			}
		}
		if (flag == false) {
			cout << "查找失败查无此人" << endl;
		}

		break;
	}
	default:
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
}
void student2::sort_emp() {
	cout << "按照成绩总分排序" << endl;
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
		cout << "总分为：" << a << "  排名为第" << i + 1 << "名" << endl;
		cout << endl;
		cout << endl;
	}
	system("pause");
	system("cls");
}
void student2::Sort_Emp() {
	cout << "按照学号进行排序" << endl;
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
	cout << "确定清空文件吗？" << endl;
	cout << "1.确定" << endl;
	cout << "2.返回" << endl;
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
		cout << "清空成功!" << endl;
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
	cout << "请输入您要找的人的姓名" << endl;
	string name = "";
	cin >> name;
	int index = this->Isexist(name);
	if (index ==-1) {
		cout << "未找到此人"<<endl;
	}
	else {
		cout << "请输入你要找的科目分数" << endl;
		cout << "1.语文" << endl
			<< "2.数学" << endl
			<< "3.英语" << endl
			<< "4.平均分" << endl;
		int k = 0;
		cin >> k;
		float a = 0;
		switch (k) {
		case 1:
			cout << "语文成绩为：" << this->m_EmpArray[index]->Chinese<<endl;
			break;
		case 2:
			cout << "数学成绩为：" << this->m_EmpArray[index]->math<<endl;
			break;
		case 3:
			cout << "英语成绩为：" << this->m_EmpArray[index]->English<<endl;
			break;
		case 4:
			a = a / 3;
			cout << "平均分为：" << a << endl;
		default:
			a = this->m_EmpArray[index]->Chinese + this->m_EmpArray[index]->math + this->m_EmpArray[index]->English;
			cout << "总分为：" << a << endl;
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
	cout << "请输入要找到分数" << endl;
	cout << "1.最高分" << endl;
	cout << "2.最低分" << endl;
	int a = 0;
	cin >> a;
	cout << "请输入要找分数的科目：" << endl;
	cout << "1.语文" << endl;
	cout << "2.数学" << endl;
	cout << "3.英语" << endl;
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
		cout << "学号：" << this->m_EmpArray[j]->id;
		cout << "  姓名为：" << this->m_EmpArray[j]->name;
		cout <<"  语文成绩为：" << this->m_EmpArray[j]->Chinese << endl;
	}
	if (a == 1 && b == 2) {
		int j = 0;
		for (int i = 0; i < this->m_EmpNum; i++) {
			if (this->m_EmpArray[i]->math > mathmax ) {
				mathmax = this->m_EmpArray[i]->math;
				j = i;
			}
		}
		cout << "学号：" << this->m_EmpArray[j]->id;
		cout << "  姓名为：" << this->m_EmpArray[j]->name;
		cout << "  数学成绩为：" << this->m_EmpArray[j]->math << endl;
	}
	if (a == 1 && b == 3) {
		int j = 0;
		for (int i = 0; i < this->m_EmpNum; i++) {
			if (this->m_EmpArray[i]->English > englishmax ) {
				englishmax = this->m_EmpArray[i]->English;
				j = i;
			}
		}
		cout << "学号：" << this->m_EmpArray[j]->id;
		cout << "  姓名为：" << this->m_EmpArray[j]->name;
		cout << "  英语成绩为：" << this->m_EmpArray[j]->English << endl;
	}
	if (a == 2 && b == 1) {
		int j = 0;
		for (int i = 0; i < this->m_EmpNum; i++) {
			if (this->m_EmpArray[i]->Chinese<Chinesemin) {
				Chinesemin = this->m_EmpArray[i]->Chinese;
				j = i;
			}
		}
		cout << "学号：" << this->m_EmpArray[j]->id;
		cout << "  姓名为：" << this->m_EmpArray[j]->name;
		cout << "  语文成绩为：" << this->m_EmpArray[j]->Chinese << endl;
	}
	if (a == 2 && b == 3) {
		int j = 0;
		for (int i = 0; i < this->m_EmpNum; i++) {
			if (this->m_EmpArray[i]->English < englishmin) {
				englishmin = this->m_EmpArray[i]->English;
				j = i;
			}
		}
		cout << "学号：" << this->m_EmpArray[j]->id;
		cout << "  姓名为：" << this->m_EmpArray[j]->name;
		cout << "  英语成绩为：" << this->m_EmpArray[j]->English << endl;
	}
	if (a == 2 && b == 2) {
		int j = 0;
		for (int i = 0; i < this->m_EmpNum; i++) {
			if (this->m_EmpArray[i]->math < mathmin) {
				mathmin = this->m_EmpArray[i]->math;
				j = i;
			}
		}
		cout << "学号：" << this->m_EmpArray[j]->id;
		cout << "  姓名为：" << this->m_EmpArray[j]->name;
		cout << "  数学成绩为：" << this->m_EmpArray[j]->math << endl;
	}
	system("pause");
	system("cls");
}