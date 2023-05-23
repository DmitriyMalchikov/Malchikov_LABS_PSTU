#include "Pair.h"
Pair::Pair() {
	first = 0;
	second = 0;
}

Pair::Pair(int f, double s) {
	first = f;
	second = s;
}

Pair::~Pair() {}

Pair::Pair(const Pair& p) {
	first = p.first;
	second = p.second;
}

Pair Pair::minus(Pair& p1, Pair& p2) {
	Pair p3;
	p3.first = p1.first - p2.first;
	p3.second = p1.second - p2.second;
	return p3;
}

Pair Pair::plusi(Pair& p1, double a) {
	Pair p2;
	p2.first = p1.first;
	p2.second = p1.second + a;
	return p2;
}

Pair Pair::plusi(Pair& p1, int a) {
	Pair p2;
	p2.second = p1.second;
	p2.first = p1.first + a;
	return p2;
}

istream& operator>>(istream& in, Pair& t) {
	cout << "int first = "; in >> t.first;
	cout << "double second = "; in >> t.second;
	return in;
}

ostream& operator<<(ostream& out, const Pair& t) {
	return (out << t.first << " : " << t.second << endl);
}

fstream& operator>>(fstream& fin, Pair& p) {
	fin >> p.first;
	fin >> p.second;
	return fin;
}

fstream& operator<<(fstream& fout, const Pair& p) {
	fout << p.first << "\n" << p.second << "\n";
	return fout;
}

bool Pair::operator<(const Pair& p) {
	double temp = p.first + p.second;
	double t = (*this).first + (*this).second;
	if (t < temp) return true;
	return false;
}