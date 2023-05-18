#include "List.h"
#include <iostream>
using namespace std;

List::List(int s)
{
	size = s;
	Node* new_node = new Node;
	new_node->data = rand() % 60;
	head_node = new_node;
	tail_node = new_node;
	for (int i = 0; i < size - 1; i++)
	{
		Node* new_node = new Node;
		new_node->data = rand() % 60;
		tail_node->pointer_to_next_node = new_node;
		new_node->pointer_to_prev_node = tail_node;
		tail_node = new_node;
	}
	tail_node->pointer_to_next_node = nullptr;
}

List::List(const List& list)
{
	Node* new_node = list.head_node;
	while (new_node != nullptr)
	{
		pushBack(new_node->data);
		new_node = new_node->pointer_to_next_node;
	}
}

List::~List()
{
	Node* current_node = head_node;
	while (current_node != nullptr) {
		head_node = current_node->pointer_to_next_node;
		delete current_node;
		current_node = head_node;
	}
}

void List::pushFront(int data)
{
	Node* new_node = new Node;
	new_node->data = data;
	if (head_node == NULL) {
		head_node = new_node;
		tail_node = new_node;
	}
	else {
		new_node->pointer_to_next_node = head_node;
		head_node->pointer_to_prev_node = new_node;
		head_node = new_node;
	}
}

void List::pushBack(int data)
{
	Node* new_node = new Node;
	new_node->data = data;
	if (head_node == NULL) {
		head_node = new_node;
		tail_node = new_node;
	}
	else {
		new_node->pointer_to_prev_node = tail_node;
		tail_node->pointer_to_next_node = new_node;
		tail_node = new_node;
	}
}

void List::popFront()
{
	Node* new_node = new Node;
	new_node = head_node->pointer_to_next_node;
	head_node->pointer_to_next_node = nullptr;
	new_node->pointer_to_prev_node = nullptr;
	delete head_node;
	head_node = new_node;
}

void List::popBack()
{
	Node* new_node = new Node;
	new_node = tail_node->pointer_to_prev_node;
	tail_node->pointer_to_prev_node = nullptr;
	new_node->pointer_to_next_node = nullptr;
	delete tail_node;
	tail_node = new_node;
}

int List::lenght()
{
	int count = 0;
	Node* current_node = head_node;
	while (current_node != nullptr) {
		current_node = current_node->pointer_to_next_node;
		count += 1;
	}
	return count;
}

void List::adding(int data, int index)
{
	if (index == 0) pushFront(data);
	else {
		if (index == lenght()) pushBack(data);
		else {
			Node* left_node = head_node;
			for (int i = 0; i < index - 1; i++)
			{
				left_node = left_node->pointer_to_next_node;
			}
			Node* new_node = new Node;
			new_node->data = data;
			new_node->pointer_to_next_node = left_node->pointer_to_next_node->pointer_to_next_node;
			Node* temp;
			temp = left_node->pointer_to_next_node;
			left_node->pointer_to_next_node = new_node;
			new_node->pointer_to_next_node = temp;
			new_node->pointer_to_prev_node = left_node;
			temp = new_node->pointer_to_next_node;
			temp->pointer_to_prev_node = new_node;
		}
	}
}

void List::removing(int index)
{
	Node* left_node = head_node;
	for (int i = 0; i < index - 1; i++)
	{
		left_node = left_node->pointer_to_next_node;
	}
	Node* temp;
	temp = left_node->pointer_to_next_node;
	left_node->pointer_to_next_node = left_node->pointer_to_next_node->pointer_to_next_node;
	left_node->pointer_to_prev_node = temp->pointer_to_prev_node;
}

int& List::operator[](int index)
{
	if (index < size && index >= 0)
	{
		Node* current_node = head_node;
		for (int i = 0; i < index; i++) {
			current_node = current_node->pointer_to_next_node;
		}
		return current_node->data;
	}
	else {
		cout << "Ошибка! Индекс больше или равен размеру списка или индекс меньше нуля" << endl;
		exit(0);
	}
}

List List::operator*(List& list)
{
	int size_temp = ((size > list.size) ? list.size : size);
	List templist(size_temp);
	for (int i = 0; i < size_temp; i++)
	{
		templist[i] = (*this)[i] * list[i];
	}
	return templist;
}

ostream& operator<<(ostream& out, const List& list)
{
	out << "\nПолученный список: ";
	Node* current_node = list.head_node;
	while (current_node != nullptr)
	{
		cout << current_node->data << " ";
		current_node = current_node->pointer_to_next_node;
	}
	out << endl;
	return out;
}

istream& operator>>(istream& in, const List& list)
{
	cout << "\nВведите список: ";
	Node* current_node = list.head_node;
	while (current_node != nullptr)
	{
		in >> current_node->data;
		current_node = current_node->pointer_to_next_node;
	}
	cout << endl;
	return in;
}

int& List::operator()()
{
	return size;
}