#pragma once
// 1) ������� ������� ������ �������� ������ ������������� (���� = 30)
// 3) � �������� [] - ��� ������ ��������� � �������� � ������� ������ ������� ������
#include <iostream>
#include <string>
#include "List.h"
using namespace std;

class error
{
	string str;
public:
	error(string s) { str = s; }
	void what() { cout << str << endl; }
};