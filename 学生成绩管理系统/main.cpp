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
			cout << "��ӭ�´�ʹ��" << endl;
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
			cout <<"Ŀǰ�ܹ���" << st.m_EmpNum<<"��ѧ��" << endl;
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
			cout << "������������������" << endl;
			system("cls");
}
	}
	return 0;
}