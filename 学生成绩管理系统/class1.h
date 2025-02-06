#pragma once
#include<string>
#include<iostream>
using namespace std;
#include"student.h"
class class1stu:public student{
public:
	class1stu(int id, string name, int c, float Chinese, float Math, float English);
	virtual void show();
	float youxiu;
	float bujige;
};