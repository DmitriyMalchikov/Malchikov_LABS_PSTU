#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

class Payday
{
	string fullname;
	double salary;
	int bonus;
public:
	Payday();
	Payday(string, double, int);
	Payday(const Payday&);
	~Payday();
	string get_fullname();
	void set_fullname(string);
	double get_salary();
	void set_salary(double);
	int get_bonus();
	void set_bonus(int);
	void show();
};
// ����������� ��� ����������
Payday::Payday()
{
	fullname = "NULL";
	salary = 0;
	bonus = 0;
	cout << "����������� ��� ���������� ��� ������� " << this << endl;
}
// ����������� � �����������
Payday::Payday(string fullname, double salary, int bonus)
{
	this->fullname = fullname;
	this->salary = salary;
	this->bonus = bonus;
	cout << "����������� � ����������� ��� ������� " << this << endl;
}
// ����������� �����������
Payday::Payday(const Payday& obj)
{
	fullname = obj.fullname;
	salary = obj.salary;
	bonus = obj.bonus;
	cout << "����������� ����������� ��� ������� " << this << endl;
}
// �������������
Payday::~Payday()
{
	cout << "������������� ��� ������� " << this << endl;
}
// ���������
string Payday::get_fullname()
{
	return fullname;
}
double Payday::get_salary()
{
	return salary;
}
int Payday::get_bonus()
{
	return bonus;
}
// ������������
void Payday::set_fullname(string fullname)
{
	this->fullname = fullname;
}
void Payday::set_salary(double salary)
{
	this->salary = salary;
}
void Payday::set_bonus(int bonus)
{
	this->bonus = bonus;
}
// ����� ���������� �� �������
void Payday::show()
{
	cout << "���: " << fullname << endl;
	cout << "�����: " << salary << endl;
	cout << "������: " << bonus << endl;
}
// ������� ������� � ���� ����������
Payday make_Payday()
{
	Payday p;
	string fullname;
	double salary;
	int bonus;
	cout << "������� ��� ����������: "; cin >> fullname;
	cout << "������� ��������: "; cin >> salary;
	cout << "������� ������: "; cin >> bonus;
	p = Payday(fullname, salary, bonus);
	return p;
}
// �������� ������� � ���� ���������
void print_Payday(Payday p)
{
	p.show();
}

int main()
{
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// ����������� ��� ����������
	Payday person1;
	person1.show();
	// ����������� � �����������
	Payday person2("��������� ������� �����������", 50000.0, 10000);
	person2.show();
	// ����������� �����������
	Payday person3(person2);
	person3.show();
	// ������������
	cout << "\n������������ ��� �������\n";
	person1.set_fullname("�������� ������� ����������");
	person1.set_salary(29301.893219);
	person1.set_bonus(8129);
	person1.show();
	// ���������
	cout << "\n��������� ��� �������\n";
	person3.set_fullname(person1.get_fullname());
	person3.set_salary(person2.get_salary());
	person3.set_bonus(person2.get_bonus());
	person3.show();
	// ������������� ������� ��� ��������
	cout << "\n����� ������� ��� ��������\n";
	print_Payday(person1);
	// ������� ���������� ������
	person2 = make_Payday();
	person2.show();
}