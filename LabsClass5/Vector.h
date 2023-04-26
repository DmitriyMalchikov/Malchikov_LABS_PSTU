#pragma once
#include <string>
#include "Person.h"
#include "Student.h"
#include <iostream>

class Vector
{
public:
	Vector(void);
	Vector(int);
	~Vector(void);
	void Add(Person*);
	void Add(Student*);
	friend ostream& operator<<(ostream& out, const Vector&);
private:
	Person** beg;
	int size;
	int current;
};

