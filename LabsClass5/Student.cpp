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
		cout << "������ �������� ��������������������!" << endl;
	}
	else {
		cout << "������ �������� ������������������!" << endl;
	}
}

istream& operator>>(istream& is, Student& s) {
	string n, sub;
	int a, g;

	cout << "������� ��� ��������: ";
	is >> n;
	s.setName(n);

	cout << "������� ������� ��������: ";
	is >> a;
	s.setAge(a);

	cout << "������� �������� ��������: ";
	is >> sub;
	s.setSubject(sub);

	cout << "������� ������: ";
	is >> g;
	s.setGrade(g);

	return is;
}

void Student::Show()
{
	cout << "���: " << name << endl;
	cout << "�������: " << age << endl;
	cout << "�������: " << subject << endl;
	cout << "������: " << grade << endl;
}