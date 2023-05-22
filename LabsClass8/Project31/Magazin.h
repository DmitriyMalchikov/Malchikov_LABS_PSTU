#pragma once
#include "Print.h"
class Magazin :
	public Print
{
public:
	Magazin();
	Magazin(int);
	Magazin(const Magazin&);
	int getnumber();
	void setnumber(int);
	string getname();
	~Magazin();
	void show();
	void input();
protected:
	int number;
};

