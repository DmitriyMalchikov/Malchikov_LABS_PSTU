#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* pointer_to_next_node = nullptr;
};

struct List {
	Node* head_node = nullptr;
	Node* tail_node = nullptr;
};

int lenght(List& list)
{
	int count = 0;
	Node* current_node = list.head_node;
	while (current_node != nullptr) {
		current_node = current_node->pointer_to_next_node;
		count += 1;
	}
	return count;
}

void pushFront(List& list, const int& data) {
	Node* new_node = new Node;
	new_node->data = data;
	if (list.head_node == nullptr) {
		list.head_node = new_node;
		list.tail_node = new_node;
	}
	else {
		Node* temp;
		temp = list.head_node;
		list.head_node = new_node;
		list.head_node->pointer_to_next_node = temp;
	}
}


void pushBack(List& list, const int& data) {
	Node* new_node = new Node;
	new_node->data = data;
	if (list.head_node == nullptr) {
		list.head_node = new_node;
		list.tail_node = new_node;
	}
	else {
		list.tail_node->pointer_to_next_node = new_node;
		list.tail_node = new_node;
	}
}

void popFront(List& list)
{
	list.head_node = list.head_node->pointer_to_next_node;
}


void popBack(List& list)
{
	Node* prev_node = list.head_node;
	while (prev_node->pointer_to_next_node != list.tail_node)
	{
		prev_node = prev_node->pointer_to_next_node;
	}
	prev_node->pointer_to_next_node = nullptr;
	list.tail_node = prev_node;
}

void printstack(List& list)
{
	Node* current_node = list.head_node;
	while (current_node != nullptr) {
		cout << " -> " << current_node->data ;
		current_node = current_node->pointer_to_next_node;
	}
	cout << endl;
}

void printqueue(List& list)
{
	Node* current_node = list.head_node;
	while (current_node != nullptr) {
		cout << current_node->data << " -> ";
		current_node = current_node->pointer_to_next_node;
	}
	cout << endl;
}


int main()
{
	setlocale(0, "");
	int a,k;
	List list;
	cout << "Что вы хотите реализовать:\n1)Стек\n2)Очередь\n";
	cin >> a;
	cout << "Введите количество элементов: ";
	cin >> k;
	int* A = new int[k];
	cout << "Введите элементы: ";
	for (int i = 0; i < k; i++)
	{
		cin >> A[i];
	}
	switch (a) {
	case(1): 
	{
		for (int i = 0; i < k; i++)
		{
			pushFront(list, A[i]);
		}
		printstack(list);
		cout << "Первый элемент равен " << list.head_node->data << ", последний элемент равен " << list.tail_node->data << endl;
		cout << "Удаление первого элемента... \n";
		popFront(list);
		printstack(list);
		break;
	}
	case(2):
	{
		for (int i = 0; i < k; i++)
		{
			pushBack(list, A[i]);
		}
		printqueue(list);
		cout << "Первый элемент равен " << list.head_node->data << ", последний элемент равен " << list.tail_node->data << endl;
		cout << "Удаление первого элемента... \n";
		popFront(list);
		printqueue(list);
		break;
	}
	default:
	{
		cout << "Ошибка выполнения";
		break;
	}
	}
	return 0;
}