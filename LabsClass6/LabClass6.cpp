#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	setlocale(0, "");
	List list1(10);
	cout << "������ ������" << list1 << endl;
	int ind;
	cout << "�������� ������� �� �������. ������� ������, ����� ����� �������: "; cin >> ind;
	cout << "\n������� �� ������� ������� ����� " << list1[ind] << endl;
	List list2(15);
	cout << "\n������ ������" << list2 << endl;
	cout << "�������� ��������� �������..." << endl;
	List list3 = list1 * list2;
	cout << list3 << endl;
	cout << "������ ������� ������ ����� " << list3() << endl;
} 