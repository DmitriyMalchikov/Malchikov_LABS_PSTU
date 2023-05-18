#pragma once
// 1) попытка создать список размером больше максимального (макс = 30)
// 3) в операции [] - при поытке обратится к элементу с номером больше размера списка
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