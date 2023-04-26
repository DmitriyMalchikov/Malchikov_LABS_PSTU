#include "Vector.h"
Vector::Vector(void)
{
	beg = 0;
	size = 0;
	current = 0;
}
Vector::~Vector(void)
{
	if (beg != 0) delete[] beg;
	beg = 0;
}
Vector::Vector(int n)
{
	beg = new Person * [n];
	current = 0;
	size = n;
}
void Vector::Add(Person* p)
{
	if (current < size)
	{
		beg[current] = p;
		current++;
	}
}

ostream& operator<<(ostream& out, const Vector& v)
{
	if (v.size == 0) out << "Пустой вектор" << endl;
	Person** p = v.beg;
	for (int i = 0; i < v.current; i++)
	{
		(*p)->Show();
		p++;
	}
	return out;
}