#pragma once
#include<string>
#include<iostream>
using namespace std;
#include"class2.h"
class2stu::class2stu(int id, string name, int c, float Chinese, float Math, float English)
{
	this->id = id;
	this->name = name;
	this->c = c;
	this->Chinese = Chinese;
	this->math = Math;
	this->English = English;
}
void class2stu::show() {
	float score = this->Chinese + this->math + this->English;
	cout << "ѧ��Ϊ��" << this->id
		<< std::left << "����Ϊ��" << this->name << "    "
		<< std::left << "�༶Ϊ��" << this->c << "    "
		<< std::left << "���ĳɼ���" << this->Chinese << "    "
		<< std::left << "��ѧ�ɼ���" << this->math << "    "
		<< std::left << "Ӣ��ɼ���" << this->English << "    "
		<< endl;
}

