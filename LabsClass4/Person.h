#pragma once
#include <string>
using namespace std;

class Person {
protected:
	string name;
	int age;

public:
	Person(string n = "NULL", int a = -1);

	void setName(std::string n);
	void setAge(int a);
	string getName();
	int getAge();
	friend istream& operator>>(istream& is, Person& p);
	void Show();
};