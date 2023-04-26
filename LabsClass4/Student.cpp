#include <iostream>
#include "Student.h"
using namespace std;


Student::Student(string n, int a, string s, int g) : Person(n, a) {
	subject = s;
	grade = g;
}

void Student::setSubject(string s) {
	subject = s;
}

void Student::setGrade(int g) {
	grade = g;
}

string Student::getSubject() {
	return subject;
}

int Student::getGrade() {
	return grade;
}

void Student::checkGrade() {
	if (grade < 3) {
		cout << "Оценка студента неудовлетворительная!" << endl;
	}
	else {
		cout << "Оценка студента удовлетворительная!" << endl;
	}
}

istream& operator>>(istream& is, Student& s) {
	string n, sub;
	int a, g;

	cout << "Введите имя студента: ";
	is >> n;
	s.setName(n);

	cout << "Введите возраст студента: ";
	is >> a;
	s.setAge(a);

	cout << "Введите название предмета: ";
	is >> sub;
	s.setSubject(sub);

	cout << "Введите оценку: ";
	is >> g;
	s.setGrade(g);

	return is;
}

void Student::Show()
{
	cout << "Имя: " << name << endl;
	cout << "Возраст: " << age << endl;
	cout << "Предмет: " << subject << endl;
	cout << "Оценка: " << grade << endl;
}