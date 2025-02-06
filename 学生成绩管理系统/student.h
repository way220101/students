#pragma once
#include<string>
#include<iostream>
using namespace std;
#include<fstream>
class student{
public:
		int id;//学号
		
		string name;//姓名
		
		float Chinese;//语文成绩
		
		float math;//数学成绩
		
		float English;//英语成绩

		int c;//班级

		virtual void show() = 0;//显示
		 
		
};
