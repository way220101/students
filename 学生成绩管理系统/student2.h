#pragma once
#include<string>
#include<iostream>
using namespace std;
#include"class1.h"
#include"class2.h"
#include"class3.h"
#include"class4.h"
#include"class5.h"
class student2{
public:
	int m_EmpNum;//记录学生人数

	student** m_EmpArray;//学生指针数组

	void Add_Emp();//添加学生

	void save();//保存文件

	bool m_FileIsEmpty;//判断文件是否为空

	int get_EmpNum();//统计现有人数

	void init_Emp();//初始化学生

	void Del_Emp();//删除学生

	int IsExist(int id);//根据学号查找学生

	void menu();//菜单显示

	void Mod_Epm();//修改学生信息

	void show_Emp();//显示学生信息

	void Find_Emp();//查找学生

	void Sort_Emp();//按照学号排序

	void Clean_File();//清空

	void danke();//查找单科成绩

	int Isexist(string name);//根据姓名找学生

	void sort_emp();//按照总成绩排序

	void find();//查找单科最高或最低


	student2();


};