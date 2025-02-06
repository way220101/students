#pragma once
#include<string>
#include<iostream>
using namespace std;
#include"student.h"
class class4stu :public student {
public:
	class4stu(int id, string name, int c, float Chinese, float Math, float English);
	float youxiu;
	virtual void show();
	float bujige;
};
