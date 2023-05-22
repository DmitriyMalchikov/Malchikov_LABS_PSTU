#pragma once
#include "Magazin.h"
class Vector
{
public:
	Vector();
	Vector(int);
	~Vector();
	void add();
	void del();
	void getname();
	void show();
	int operator()();
protected:
	Object** beg;
	int size;
	int curr;
};

