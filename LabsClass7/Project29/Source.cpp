#include "List.h"
#include "Pair.h"
#include <Windows.h>

int main() {
	SetConsoleCP(1251); SetConsoleOutputCP(1251);
	Pair p1(2, 2.5);
	List<Pair> a(3, p1);
	cout << "first list: ";
	cout << a << endl;
	cout << "creating personal list: ";
	cin >> a;
	cout << a << endl;
	List<Pair> b(a);
	cout << "copied list: ";
	cout << b << endl;
	List<Pair> c = a * b;
	cout << "a * b\n" << c << endl;
	Pair num;
	cout << "Enter number to add:\n"; cin >> num;
	b.pushback(num);
	for (Iterator<Pair> iter = b.first(); iter != b.last(); ++iter)
		cout << *iter << '\n';
	system("pause");
	return 0;
}