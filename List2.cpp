#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* pointer_to_prev_node = nullptr;
	Node* pointer_to_next_node = nullptr;
};

struct List {
	Node* head_node = nullptr;
	Node* tail_node = nullptr;
};

void pushFront(List& list, int data)
{
	Node* new_node = new Node;
	new_node->data = data;
	if (list.head_node == NULL) {
		list.head_node = new_node;
		list.tail_node = new_node;
	}
	else {
		new_node->pointer_to_next_node = list.head_node;
		list.head_node->pointer_to_prev_node = new_node;
		list.head_node = new_node;
	}
}

void pushBack(List& list, int data)
{
	Node* new_node = new Node;
	new_node->data = data;
	if (list.head_node == NULL) {
		list.head_node = new_node;
		list.tail_node = new_node;
	}
	else {
		new_node->pointer_to_prev_node = list.tail_node;
		list.tail_node->pointer_to_next_node = new_node;
		list.tail_node = new_node;
	}
}

void popFront(List& list)
{
	Node* new_node = new Node;
	new_node = list.head_node->pointer_to_next_node;
	list.head_node->pointer_to_next_node = nullptr;
	new_node->pointer_to_prev_node = nullptr;
	delete list.head_node;
	list.head_node = new_node;
}

void popBack(List& list)
{
	Node* new_node = new Node;
	new_node = list.tail_node->pointer_to_prev_node;
	list.tail_node->pointer_to_prev_node = nullptr;
	new_node->pointer_to_next_node = nullptr;
	delete list.tail_node;
	list.tail_node = new_node;
}

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

void adding(List& list,int data, int index)
{
	if (index == 0) pushFront(list, data);
	else {
		if (index == lenght(list)) pushBack(list, data);
		else {
			Node* left_node = list.head_node;
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

void removing(List& list, int index)
{
	Node* left_node = list.head_node;
	for (int i = 0; i < index - 1; i++)
	{
		left_node = left_node->pointer_to_next_node;
	}
	Node* temp;
	temp = left_node->pointer_to_next_node;
	left_node->pointer_to_next_node = left_node->pointer_to_next_node->pointer_to_next_node;
	left_node->pointer_to_prev_node = temp->pointer_to_prev_node;
}

void printStart(List& list)
{
	Node* current_node = list.head_node;
	while (current_node != nullptr) {
		cout << current_node->data << ' ';
		current_node = current_node->pointer_to_next_node;
	}
	cout << endl;
}

void printFinish(List& list)
{
	Node* current_node = list.tail_node;
	while (current_node != nullptr) {
		cout << current_node->data << ' ';
		current_node = current_node->pointer_to_prev_node;
	}
	cout << endl;
}

int main()
{
	setlocale(0, "");
	int n, s, k;
	List list;
	cout << "������� ������ ������: "; cin >> n;
	int* A = new int[n];
	cout << "������� �������� ������: ";
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		pushBack(list, A[i]);
	}
	cout << "����� � ������ ������: ";
	printStart(list);
	cout << "����� � ����� ������: ";
	printFinish(list);
	cout << "1)������� �������, ������� ��������� � ������ ������: ";
	cin >> n;
	pushFront(list, n);
	cout << "������ ����� ����������: ";
	printStart(list);
	cout << "2)������� �������, ������� ��������� � ����� ������: ";
	cin >> n;
	pushBack(list, n);
	cout << "������ ����� ����������: ";
	printStart(list);
	cout << "3)�������� �������� �� ������ ������...";
	popFront(list);
	cout << "\n������ ����� ��������: ";
	printStart(list);
	cout << "4)�������� �������� �� ����� ������...";
	popBack(list);
	cout << "\n������ ����� ��������: ";
	printStart(list);
	cout << "5)������� ���������� � ��������� � ����� ��������, ����� ������� ��� ����������: ";
	cin >> k >> s;
    int* B = new int[k];
	cout << "������� ���� ��������: ";
	for (int i = 0; i < k; i++) {
		cin >> B[i];
	}
	for (int i = 0; i < k; i++) {
		adding(list, B[i], s);
		s++;
	}
	cout << "������ ����� ����������: ";
	printStart(list);
	cout << "6) ������� ���������� � ��������� � ����� ��������, � �������� �������� �������� � ����� ������� �������� ��������: ";
	cin >> k >> s;
	for (int i = 0; i < k; i++) {
		removing(list, s);
		s -= 1;
	}
	cout << "������ ����� ��������: ";
	printStart(list);
}