#pragma once
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* pointer_to_prev_node = nullptr;
	Node* pointer_to_next_node = nullptr;
};

class List {
private:
	int size;
	Node* head_node = nullptr;
	Node* tail_node = nullptr;
public:
	List(int s);
	List(const List&);
	~List();
	void pushFront(int);
	void pushBack(int);
	void popFront();
	void popBack();
	int lenght();
	void adding(int, int);
	void removing(int);
	int& operator[](int);
	int& operator()();
	List operator*(List&);
	friend ostream& operator<<(ostream& out, const List&);
	friend istream& operator>>(istream& in, const List&);
};

