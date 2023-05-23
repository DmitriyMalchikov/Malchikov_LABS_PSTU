#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Pair
{
public:
	Pair();
	Pair(int, double);
	Pair(const Pair&);
	~Pair();
	Pair minus(Pair&, Pair&);
	Pair plusi(Pair&, double);
	Pair plusi(Pair&, int);
	friend istream& operator>>(istream& in, Pair& p);
	friend ostream& operator<<(ostream& out, const Pair& p);
	friend fstream& operator>>(fstream& fin, Pair& p);
	friend fstream& operator<<(fstream& fout, const Pair& p);
	bool operator<(const Pair&);
protected:
	int first;
	double second;
};

