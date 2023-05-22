#include "Magazin.h"

Magazin::Magazin()
{
	name = "NULL";
	author = "NULL";
	number = 0;
}

Magazin::~Magazin()
{
}

Magazin::Magazin(int n)
{
	number = n;
}

int Magazin::getnumber()
{
	return number;
}

void Magazin::setnumber(int n)
{
	number = n;
}

string Magazin::getname() {
	return name;
}

void Magazin::show()
{
	cout << endl << "Number of pages: " << number << endl;
	cout << "Name of book: " << name << endl;
	cout << "Author: " << author << endl;
}

void Magazin::input()
{
	cout << endl << "Number of pages?: "; cin >> number;
	cout << "Name of book?: "; cin >> name;
	cout << "Author?: "; cin >> author;
}
