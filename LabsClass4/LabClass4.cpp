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

	cout << "Имя: " << student.getName() << endl;
	cout << "Возраст: " << student.getAge() << endl;
	cout << "Предмет: " << student.getSubject() << endl;
	cout << "Оценка: " << student.getGrade() << endl;

	student.checkGrade();

	return 0;
}