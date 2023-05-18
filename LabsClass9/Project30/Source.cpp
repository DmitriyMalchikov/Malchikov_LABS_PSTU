#include <iostream>
#include "Error.h"
#include "List.h"
using namespace std;

int main()
{
	try
	{
		List<int> mylist;
		int s;
		cout << "enter size (maxsize = 20): ";
		cin >> s;
		mylist = List<int>(s, 5);
		cin >> mylist;
		cout << mylist << endl;
		int i;
		cout << "what index you want to return?"; cin >> i;
		int a;
		a = mylist[i];
		cout << "return value is " << a << endl;
	}
	catch (error e) {
		e.what();
	}
	system("pause");
	return 0;
}