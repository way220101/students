#include<iostream>
using namespace std;
#include"student.h"
#include"student2.h"
int main() {
	while (true) {
		student2 st;
		st.menu();
		int a = 0;
		cin >> a;
		switch (a) {
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		case 1:
			st.Add_Emp();
			break;
		case 2:
			st.show_Emp();
			break;
		case 3:
			st.Del_Emp();
			break;
		case 4:
			st.Mod_Epm();
			break;
		case 5:
			st.Find_Emp();
			break;
		case 6:
			st.Sort_Emp();
			break;
		case 7:
			st.Clean_File();
			break;
		case 8:
			cout <<"目前总共有" << st.m_EmpNum<<"个学生" << endl;
			system("pause");
			system("cls");
			break;
		case 9:
			st.danke();
			break;
		case 10:
			st.sort_emp();
			break;
		case 11:
			st.find();
			break;
		default:
			cout << "输入有误请重新输入" << endl;
			system("cls");
}
	}
	return 0;
}