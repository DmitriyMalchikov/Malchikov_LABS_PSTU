#include "Person.h"
#include <iostream>
using namespace std;

Person::Person(string n, int a) {
	name = n;
	age = a;
}

void Person::setName(string n) {
	name = n;
}

void Person::setAge(int a) {
	age = a;
}

string Person::getName() {
	return name;
}

int Person::getAge() {
	return age;
}

void Person::Show()
{
	cout << "Имя: " << name << endl;
	cout << "Возраст: " << age << endl;
}

istream& operator>>(istream& is, Person& p) {
	string n;
	int a;

	cout << "Введите имя: ";
	is >> n;
	p.setName(n);

	cout << "Введите возраст: ";
	is >> a;
	p.setAge(a);

	return is;
}