#include <iostream>
#include "Person.h"
#include "Student.h"
#include <windows.h>
using namespace std;

int main() {
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Student student;
	cin >> student;

	cout << "���: " << student.getName() << endl;
	cout << "�������: " << student.getAge() << endl;
	cout << "�������: " << student.getSubject() << endl;
	cout << "������: " << student.getGrade() << endl;

	student.checkGrade();

	return 0;
}