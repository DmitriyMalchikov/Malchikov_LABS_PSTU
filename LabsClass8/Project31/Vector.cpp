#include "Vector.h"

Vector::Vector() {
	beg = nullptr;
	size = 0;
	curr = 0;
}

Vector::~Vector(void) {}

Vector::Vector(int n) {
	beg = new Object* [n]; 
	curr = 0;
	size = n;
}

void Vector::getname() {
	Object** p = beg;
	for (int i = 0; i < curr; i++) {
		cout << "Name: " << (*p)->getname() << endl;
		p++;
	}
}

void Vector::add() {
	Object* p;
	cout << "What to create? 1. Print, 2. Magazin" << endl;
	int x;
	cin >> x;
	if (x == 1) {
		Print* a = new (Print);
		a->input(); 
		p = a;
		if (curr < size) {
			beg[curr] = p;
			curr++;
		}
	}
	else if (x == 2) { 
		Magazin* b = new Magazin;
		b->input();
		p = b;
		if (curr < size) {
			beg[curr] = p;
			curr++;
		}
	}
	else return;
}

void Vector::show() {
	if (curr == 0) cout << "Empty" << endl;
	Object** p = beg; 
	for (int i = 0;i < curr;i++) {
		(*p)->show(); 
		p++;
	}
}

int Vector::operator ()() {
	return curr;
}

void Vector::del() {
	if (curr == 0) return; 
	curr--;
}