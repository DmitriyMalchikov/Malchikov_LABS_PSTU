#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	setlocale(0, "");
	List list1(10);
	cout << "Первый список" << list1 << endl;
	int ind;
	cout << "Операция доступа по индексу. Введите индекс, чтобы найти элемент: "; cin >> ind;
	cout << "\nЭлемент по данному индексу равен " << list1[ind] << endl;
	List list2(15);
	cout << "\nВторой список" << list2 << endl;
	cout << "Операция умножения списков..." << endl;
	List list3 = list1 * list2;
	cout << list3 << endl;
	cout << "Размер данного списка равен " << list3() << endl;
} 