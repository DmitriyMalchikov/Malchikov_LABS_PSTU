#pragma once
#include "Object.h"
class Print :
	public Object
{
public:
	Print();
	Print(string, string);
	void show();
	void input();
	string getname();
	string getauthor();
	void setname(string);
	void setauthor(string);
	~Print();
protected:
	string name;
	string author;
};

