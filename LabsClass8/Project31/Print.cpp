#include "Print.h"



Print::Print()
{
	name = "NULL";
	author = "NULL";
}

Print::~Print()
{
}

Print::Print(string n, string a)
{
	name = n;
	author = a;
}

void Print::show()
{
	cout << endl;
	cout << "Name: " << name << endl;
	cout << "Author: " << author << endl;
}

void Print::input()
{
	cout << "Name?: "; cin >> name;
	cout << "Author?: "; cin >> author;
	cout << endl;
}

string Print::getname()
{
	return name;
}

string Print::getauthor()
{
	return author;
}

void Print::setname(string n)
{
	name = n;
}

void Print::setauthor(string a)
{
	author = a;
}

