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
	int m_EmpNum;//��¼ѧ������

	student** m_EmpArray;//ѧ��ָ������

	void Add_Emp();//���ѧ��

	void save();//�����ļ�

	bool m_FileIsEmpty;//�ж��ļ��Ƿ�Ϊ��

	int get_EmpNum();//ͳ����������

	void init_Emp();//��ʼ��ѧ��

	void Del_Emp();//ɾ��ѧ��

	int IsExist(int id);//����ѧ�Ų���ѧ��

	void menu();//�˵���ʾ

	void Mod_Epm();//�޸�ѧ����Ϣ

	void show_Emp();//��ʾѧ����Ϣ

	void Find_Emp();//����ѧ��

	void Sort_Emp();//����ѧ������

	void Clean_File();//���

	void danke();//���ҵ��Ƴɼ�

	int Isexist(string name);//����������ѧ��

	void sort_emp();//�����ܳɼ�����

	void find();//���ҵ�����߻����


	student2();


};