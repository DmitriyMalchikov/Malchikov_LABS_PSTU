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
// Конструктор без параметров
Payday::Payday()
{
	fullname = "NULL";
	salary = 0;
	bonus = 0;
	cout << "Конструктор без параметров для объекта " << this << endl;
}
// Конструктор с параметрами
Payday::Payday(string fullname, double salary, int bonus)
{
	this->fullname = fullname;
	this->salary = salary;
	this->bonus = bonus;
	cout << "Конструктор с параметрами для объекта " << this << endl;
}
// Конструктор копирования
Payday::Payday(const Payday& obj)
{
	fullname = obj.fullname;
	salary = obj.salary;
	bonus = obj.bonus;
	cout << "Конструктор копирования для объекта " << this << endl;
}
// Деконструктор
Payday::~Payday()
{
	cout << "Деконструктор для объекта " << this << endl;
}
// Селекторы
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
// Модификаторы
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
// Вывод информации об объекте
void Payday::show()
{
	cout << "ФИО: " << fullname << endl;
	cout << "Оклад: " << salary << endl;
	cout << "Премия: " << bonus << endl;
}
// Возврат объекта в виде результата
Payday make_Payday()
{
	Payday p;
	string fullname;
	double salary;
	int bonus;
	cout << "Введите ФИО сотрудника: "; cin >> fullname;
	cout << "Введите зарплату: "; cin >> salary;
	cout << "Введите премию: "; cin >> bonus;
	p = Payday(fullname, salary, bonus);
	return p;
}
// Передача объекта в виде параметра
void print_Payday(Payday p)
{
	p.show();
}

int main()
{
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// Конструктор без параметров
	Payday person1;
	person1.show();
	// Конструктор с параметрами
	Payday person2("Мальчиков Дмитрий Григорьевич", 50000.0, 10000);
	person2.show();
	// Конструктор копирования
	Payday person3(person2);
	person3.show();
	// Модификаторы
	cout << "\nМодификаторы для объекта\n";
	person1.set_fullname("Беркутов Дмитрий Викторович");
	person1.set_salary(29301.893219);
	person1.set_bonus(8129);
	person1.show();
	// Селекторы
	cout << "\nСелекторы для объекта\n";
	person3.set_fullname(person1.get_fullname());
	person3.set_salary(person2.get_salary());
	person3.set_bonus(person2.get_bonus());
	person3.show();
	// Использование объекта как параметр
	cout << "\nВывод объекта как параметр\n";
	print_Payday(person1);
	// Функция возвращает объект
	person2 = make_Payday();
	person2.show();
}