#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Vector.h"
#include <windows.h>
using namespace std;

int main() {
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Vector v(5);
	Person a;
	cin >> a;
	Student b;
	cin >> b;
	Person* p = &a;
	v.Add(p);
	p = &b;
	v.Add(p);
	cout << v;
	return 0;
}