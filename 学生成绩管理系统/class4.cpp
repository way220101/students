#pragma once
#include<string>
#include<iostream>
using namespace std;
#include"class4.h"
class4stu::class4stu(int id, string name, int c, float Chinese, float Math, float English)
{
	this->id = id;
	this->name = name;
	this->c = c;
	this->Chinese = Chinese;
	this->math = Math;
	this->English = English;
}
void class4stu::show() {
	float score = this->Chinese + this->math + this->English;
	cout << "学号为：" << this->id
		<< std::left << "姓名为：" << this->name << "    "
		<< std::left << "班级为：" << this->c << "    "
		<< std::left << "语文成绩：" << this->Chinese << "    "
		<< std::left << "数学成绩：" << this->math << "    "
		<< std::left << "英语成绩：" << this->English << "    "
		<< endl;
}
