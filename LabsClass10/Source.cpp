#include "Pair.h"
#include "file_work.h" 
#include <iostream> 
#include <fstream>
#include <string> 
#include <Windows.h>
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Pair p, temp;
	int k, c, num, count;
	double plus;
	char file_name[30];
	do {
		system("pause"); system("cls");
		cout << "1) Make file";
		cout << "\n2) Print file";
		cout << "\n3) Remove pairs that are lower than this pair";
		cout << "\n4) Add some pairs after given number";
		cout << "\n5) Add number to all pairs";
		cout << "\n0) Exit\n";
		cin >> c;
		switch (c) {
		case 1:
			cout << "File name: ";
			cin >> file_name;
			k = make_file(file_name);
			if (k < 0) {
				cout << "Can't create file\n";
			}
			break;
		case 2:
			cout << "File name: ";
			cin >> file_name;
			k = print_file(file_name);
			if (k == 0) {
				cout << "Empty file\n";
			}
			break;
		case 3:
			cout << "File name: ";
			cin >> file_name;
			cin >> temp;
			k = del_file(file_name, temp);
			if (k < 0) {
				cout << "Can't read file\n";
				break;
			}
			break;
		case 4:
			cout << "File name: "; cin >> file_name;
			cout << "After number: "; cin >> num;
			cout << "Number of pairs: "; cin >> count;
			k = add_file(file_name, num, count);
			if (k < 0) {
				cout << "Can't read file\n";
			}
			if (k == 0) {
				k = add_end(file_name, count);
				break;
			}
			break;
		case 5:
			cout << "File name: ";
			cin >> file_name;
			cout << "Enter number to add: ";
			cin >> plus;
			k = change_file(file_name, plus);
			if (k < 0) {
				cout << "Can't read file\n";
			}
			break;
		}
	} while (c != 0);
	return 0;
}