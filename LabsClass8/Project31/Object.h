#pragma once
#include <iostream>
#include <string>
using namespace std;
class Object
{
public:
	Object() {};
	~Object() {};
	virtual void show() = 0;
	virtual void input() = 0;
	virtual string getname() = 0;
};