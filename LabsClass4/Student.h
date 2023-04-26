#pragma once
#include "Person.h"
class Student : public Person {
private:
	string subject;
	int grade;

public:
	Student(string n = "", int a = 0, string s = "", int g = 0);
	void setSubject(string s);
	void setGrade(int g);
	string getSubject();
	int getGrade();
	void checkGrade();
	void Show();
	friend istream& operator>>(istream& is, Student& s);
};

