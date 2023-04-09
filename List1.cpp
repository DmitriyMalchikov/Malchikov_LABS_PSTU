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

void adding(List& list, int value, int index)
{
	if (index > lenght(list)) return;
	if (index == 0)	
	{
		pushFront(list, value);
	}
	else if (index == lenght(list))	
	{
		pushBack(list, value);
	}
	else
	{
		Node* prev_node = list.head_node;
		for (int i = 0; i < index - 1; i++)
		{
			prev_node = prev_node->pointer_to_next_node;
		}
		Node* new_node = new Node;
		new_node->data = value;
		new_node->pointer_to_next_node = prev_node->pointer_to_next_node->pointer_to_next_node;
		Node* temp;
		temp = prev_node->pointer_to_next_node;
		prev_node->pointer_to_next_node = new_node;
		new_node->pointer_to_next_node = temp;
	}
}

void removing(List& list, int index)
{
	Node* prev_node = list.head_node;
	for (int i = 0; i < index - 1; i++)
	{
		prev_node = prev_node->pointer_to_next_node;
	}
	prev_node->pointer_to_next_node = prev_node->pointer_to_next_node->pointer_to_next_node;
}

void print(List& list)
{
	Node* current_node = list.head_node;
	while (current_node != nullptr) {
		cout << current_node->data << ' ';
		current_node = current_node->pointer_to_next_node;
	}
	cout << endl;
}

int main()
{
	setlocale(0, "");
	List list;
	cout << "Введите размер списка: ";
	int n;
	cin >> n;
	cout << "Введите элементы списка: ";
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		pushBack(list, a);
	}
	cout << "1)Введите элемент, который добавится в начало списка: ";
	cin >> n;
	pushFront(list,n);
	cout << "Список после добавления: ";
	print(list);
	cout << "2)Введите элемент, который добавится в конец списка: ";
	cin >> n;
	pushBack(list, n);
	cout << "Список после добавления: ";
	print(list);
	cout << "3)Удаление элемента из начала списка...";
	popFront(list);
	cout << "\nСписок после удаления: ";
	print(list);
	cout << "4)Удаление элемента из конца списка...";
	popBack(list);
	cout << "\nСписок после удаления: ";
	print(list);
	cout << "5)Введите количество К элементов и номер элемента, перед которым они добавлятся: ";
	int s, k;
	cin >> k >> s;
	int* A = new int[k];
	cout << "Введите сами элементы: ";
	for (int i = 0; i < k; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < k; i++) {
		adding(list, A[i], s);
		s++;
	}
	cout << "Список после добавления: ";
	print(list);
	cout << "6) Введите количество К элементов и номер элемента, с которого начнется удаление и перед которым удалятся элементы: ";
	cin >> k >> s;
	for (int i = 0; i < k; i++) {
		removing(list, s);
		s -= 1;
	}
	cout << "Список после удаления: ";
	print(list);
}