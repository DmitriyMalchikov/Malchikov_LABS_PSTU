#include <iostream>
using namespace std;

class fraction
{
	double first;
	double second;
public:
	int j;
	void Read();
	void Init(double, double);
	void Show();
	double element(int);
};

void fraction::Read()
{
	cout << "first? "; cin >> first;
	cout << "second? "; cin >> second;
	cout << "j? "; cin >> j;
	cout << endl;
}

void fraction::Show()
{
	cout << "first = " << first << endl;
	cout << "second = " << second << endl;
}

void fraction::Init(double first, double second)
{
	this->first = first;
	this->second = second;
}

double fraction::element(int j)
{
	this->j = j;
	double final = first;
	for (int i = 0; i < j; i++) {
		final *= second;
	}
	cout << "element = " << final << endl;
	return final;
}

fraction make_fraction()
{
	fraction t;
	t.Read();
	return t;
}

int main()
{
	setlocale(0, "");
	fraction A, B;
	cout << "With const - \n";
	A.Init(3.0, 2.0); // Константное выражение
	A.Show();
	A.element(4);

	cout << "\nWith variable - \n";
	B.Read();  // Переменное выражение
	B.Show();
	B.element(B.j);

	cout << "\nWith dinamic variable - \n";
	fraction* X = new fraction; // Динамическая переменная
	X->Init(5.0, 10.0);
	X->Show();
	X->element(5);

	cout << "\nWith static array - \n";
	fraction mass[3]; // Статический массив
	for (int i = 0; i < 3; i++) {
		cout << i + 1 << " element:\n";
		mass[i].Read();
		mass[i].Show();
		mass[i].element(mass[i].j);
	}

	cout << "\nWith dinamic array - \n";
	fraction* d_mass = new fraction[3]; // Динамический массив
	for (int i = 0; i < 3; i++) {
		cout << i + 1 << " element:\n";
		d_mass[i].Read();
		d_mass[i].Show();
		d_mass[i].element(d_mass[i].j);
	}

	cout << "\nWith make_fraction - \n";
	fraction F = make_fraction(); // make_fraction
	F.Show();
	F.element(F.j);
}