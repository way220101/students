#pragma once
#include<string>
#include<iostream>
using namespace std;
#include<fstream>
class student{
public:
		int id;//ѧ��
		
		string name;//����
		
		float Chinese;//���ĳɼ�
		
		float math;//��ѧ�ɼ�
		
		float English;//Ӣ��ɼ�

		int c;//�༶

		virtual void show() = 0;//��ʾ
		 
		
};
