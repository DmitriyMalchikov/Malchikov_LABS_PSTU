#include <iostream>
#include <string>
#include <Windows.h>
#include <ctime>
#include <fstream>
using namespace std;

string name[10] = { "Дмитрий", "Максим", "Андрей", "Иван", "Петр", "Константин", "Артем", "Анатолий", "Степан", "Георгий" };
string surname[10] = { "Мальчиков", "Онянов", "Петраков", "Лучезаров", "Баранов", "Беркутов", "Колоткин", "Карамышев", "Баранов", "Восторкнутов" };
string patronymic[10] = { "Григорьевич", "Иванович", "Петрович", "Андреевич", "Степанович", "Романович", "Максимович", "Данилович", "Константинович", "Олегович" };
string date[10] = { "02.07.2004", "29.01.2000", "15.03.2001", "19.03.2002", "19.09.2003", "10.07.2000", "01.09.2004", "21.04.2000", "07.07.2003", "08.10.2001" };
string passport[10] = { "590633", "823910", "892103", "489321", "839120", "382139", "832019", "793219", "401923", "519023" };

struct Human {
    string name = "NULL";
    string surname = "NULL";
    string patronymic = "NULL";
    string date = "NULL";
    string passport = "NULL";
    Human* next = nullptr;

    void SetHuman(string name, string surname, string patronymic, string date, string passport) {
        this->name = name;
        this->surname = surname;
        this->patronymic = patronymic;
        this->date = date;
        this->passport = passport;
    }
    void PrintHuman() {
        cout << "ФИО:\t" << this->surname << ' ' << this->name << ' ' << this->patronymic << endl;
        cout << "Дата рождения:\t" << this->date << endl;
        cout << "Номер пасспорта:\t" << this->passport << endl;
        cout << "---------------------------" << endl;
    }
    void CopyHuman(Human* copy) {
        this->name = copy->name;
        this->surname = copy->surname;
        this->patronymic = copy->patronymic;
        this->date = copy->date;
        this->passport = copy->passport;
        this->next = nullptr;
    }
};

struct List {
    int size = 0;
    Human* head = nullptr;
    Human* tail = nullptr;
};


bool Empty(List* list) {
    return list == nullptr || list->size == 0;
}

void PushBack(List* list) {
    Human* ptr = new Human;
    string Name = name[rand() % 10];
    string Surname = surname[rand() % 10];
    string Patronimic = patronymic[rand() % 10];
    string Date = date[rand() % 10];
    string Passport = passport[rand() % 10];
    ptr->SetHuman(Name, Surname, Patronimic, Date, Passport);
    ptr->next = nullptr;
    if (Empty(list)) {
        list->head = ptr;
        list->tail = ptr;
    }
    else if (list->size == 1) {
        list->tail->next = ptr;
        list->tail = ptr;
        list->head->next = list->tail;
    }
    else {
        list->tail->next = ptr;
        list->tail = ptr;
    }
    list->size++;
}

List* CreateList(int size) {
    List* list = new List;
    for (int i = 0; i < size; i++)
        PushBack(list);
    return list;
}

void PushFront(List* list) {
    Human* p = new Human;
    string Name = name[rand() % 10];
    string Surname = surname[rand() % 10];
    string Patronimic = patronymic[rand() % 10];
    string Date = date[rand() % 10];
    string Passport = passport[rand() % 10];
    p->SetHuman(Name, Surname, Patronimic, Date, Passport);
    if (Empty(list)) {
        list->head = p;
        list->tail = p;
    }
    else {
        p->next = list->head;
        list->head = p;
    }
    list->size++;
}


void PrintList(List* list) {
    if (Empty(list)) cout << "Список пуст\n";
    else {
        int i = 1;
        Human* temp = list->head;
        cout << "---------------------------\n";
        cout << "\tСписок\n";
        while (i <= list->size) {
            temp->PrintHuman();
            temp = temp->next;
            ++i;
        }
    }
}

void removingKey(List* list, string k) {
    Human* temp = list->head;
    if (temp->date == k) {
        list->head = temp->next;
        delete temp;
        list->size--;
        cout << "Удаление элемента...\nЭлемент удалён!\n";
        return;
    }
    while (temp->next->date != k) {
        temp = temp->next;
    }
    if (temp != nullptr) {
        cout << "Удаление элемента...\nЭлемент удалён!\n";
        Human* r = temp->next;
        temp->next = r->next;
        delete r;
        list->size--;
        r = temp->next;
        return;
    }
    else {
        cout << "Ошибка: элемента не существует\n";
    }
}

void removingIndex(List* list, int n) {
    Human* temp = list->head;
    int i = 1;
    if (i == n) {
        list->head = temp->next;
        delete temp;
        list->size--;
        return;
    }
    else
    {
        while (i + 1 != n) {
            i++;
            temp = temp->next;
        }
        temp->next = temp->next->next;
        list->size--;
        return;
    }
}

void adding(List* list, int number) {
    int i = 1;
    string key;
    Human* temp = list->head;
    if (i == number) {
        PushFront(list);
        temp = list->head;
    }
    else {
        while (i + 1 != number) {
            temp = temp->next;
            i++;
        }
        Human* p = new Human;
        p->next = temp->next;
        temp->next = p;
        string Name = name[rand() % 10];
        string Surname = surname[rand() % 10];
        string Patronimic = patronymic[rand() % 10];
        string Date = date[rand() % 10];
        string Passport = passport[rand() % 10];
        p->SetHuman(Name, Surname, Patronimic, Date, Passport);
        temp = p;
        list->size++;
    }
}

int hashFunc(string human, int size) {
    double a = ((sqrt(5) - 1) / 2) * stoi(human.substr(0, 2)) + stoi(human.substr(3, 2)) + stoi(human.substr(6, 4));
    double c = size * (a - static_cast<int>(a));
    return static_cast<int>(c);
}

Human** MethodAddress(List* l) {
    int size = l->size, pos, collisions_count = 0;
    Human** table = new Human * [size];
    for (int i = 0; i < size; i++) {
        table[i] = new Human;
    }
    Human* human = l->head;
    for (int i = 0; i < size; i++) {
        pos = hashFunc(human->date, size);
        if (table[pos]->date == "NULL") {
            table[pos] = human;
            human = human->next;
        }
        else {
            while (table[pos]->date != "NULL") {
                pos++;
                collisions_count++;
                if (pos >= size) pos = pos - size;
            }
            table[pos] = human;
            human = human->next;
        }
    }
    cout << "Кол-во коллизий = " << collisions_count << endl;
    cout << "======================" << endl;
    return table;
}

Human** MethodChain(List* list) {
    int size = list->size, collisions_count = 0;
    Human** table = new Human * [size];
    for (int i = 0; i < size; i++) table[i] = new Human;
    Human* current_human = list->head;
    Human* human = new Human, * r;
    human->CopyHuman(current_human);
    for (int i = 0; i < size; i++) {
        int pos;
        pos = hashFunc(current_human->date, size);
        if (table[pos]->date == "NULL") {
            table[pos] = human;
        }
        else {
            collisions_count++;
            r = table[pos];
            human->next = r;
            table[pos] = human;
        }
        human = new Human;
        if (current_human->next != nullptr) {
            current_human = current_human->next;
            human->CopyHuman(current_human);
        }
    }
    cout << "Кол-во коллизий = " << collisions_count << endl;
    cout << "======================" << endl;
    return table;
}

void PrintHash(Human** table, int size, int type) {
    ofstream fout;
    fout.open("Info.txt");
    if (type == 1) for (int i = 0; i < size; i++) {
        cout << i + 1 << ":\n";
        table[i]->PrintHuman();
        fout << i + 1 << ":\n";
        if (table[i]->surname == "NULL") {
            fout << "---------------------------" << endl;
            fout << "\n\n";
        }
        else
        {
            fout << "ФИО:\t" << table[i]->surname << ' ' << table[i]->name << ' ' << table[i]->patronymic << endl;
            fout << "Дата рождения:\t" << table[i]->date << endl;
            fout << "Номер пасспорта:\t" << table[i]->passport << endl;
            fout << "---------------------------" << endl;
        }
    }
    else {
        for (int i = 0; i < size; i++) {
            cout << i + 1 << ":\n";
            fout << i + 1 << ":\n";
            Human* human = table[i];
            do {
                human->PrintHuman();
                if (human->surname == "NULL") {
                    fout << "---------------------------" << endl;
                    fout << "\n\n\n";
                    fout << "---------------------------" << endl;
                    human = human->next;
                }
                else
                {
                    fout << "ФИО:\t" << human->surname << ' ' << human->name << ' ' << human->patronymic << endl;
                    fout << "Дата рождения:\t" << human->date << endl;
                    fout << "Номер пасспорта:\t" << human->passport << endl;
                    fout << "---------------------------" << endl;
                    human = human->next;
                    cout << endl;
                }
            } while (human != nullptr);
        }
    }
    fout.close();
}

void menu() {
    cout << "Меню\n";
    cout << "1)Cоздать список\n";
    cout << "2)Вывод списка\n";
    cout << "3)Добавить элемент в начало списка.\n";
    cout << "4)Добавить элемент в середину списка.\n";
    cout << "5)Добавить элемент в конец списка.\n";
    cout << "6)Удалить элемент.\n";
    cout << "7)Удалить элемент с заданным ключем.\n";
    cout << "8)Удалить список.\n";
    cout << "9)Провести хэширование методом открытой адресации и записать в файл.\n";
    cout << "10)Провести хэширование методом цепочек и записать в файл.\n";
    cout << "0 - Останов программы.\n";
}

void Menu() {
    int n, size_list, number, count;
    List* list = new List;
    string key;
    Human** table;
    Human* human;
    string date; int pos, counter = 0;
    bool flag;
    n = 1;
    while (n != 0) {
        system("pause");
        system("cls");
        menu();
        cin >> n;
        switch (n) {
        case 0:
            cout << "Завершение программы.... (окно можно закрыть)";
            break;
        case 1:
            cout << "Введите размер списка: ";
            cin >> size_list;
            list = CreateList(size_list);
            break;
        case 2:
            PrintList(list);
            break;
        case 3:
            PushFront(list);
            break;
        case 4:
            cout << "Введите номер заданного элемента: ";
            cin >> number;
            while (number <= 0 || number > list->size) {
                cout << "Номер должен быть больше нуля и меньше " << list->size + 1 << "!Введите номер : ";
                cin >> number;
            }
            adding(list, number);
            break;
        case 5:
            PushBack(list);
            break;
        case 6:
            cout << "Введите номер заданного элемента: ";
            cin >> number;
            removingIndex(list, number);
            break;
        case 7:
            cout << "Введите ключ: ";
            getline(cin, key); getline(cin, key);
            removingKey(list, key);
            break;
        case 8:
            while (!Empty(list)) {
                removingIndex(list, 1);
            }
            cout << "Список удалён!\n";
            break;
        case 9:
            counter = 0;
            table = MethodAddress(list);
            PrintHash(table, list->size, 1);
            cout << "Введите дату рождения: ";
            getline(cin, date); getline(cin, date);
            cout << "---------------------------" << endl;
            while (date.length() != 10) {
                cout << "Введите дату рождения: ";
                getline(cin, date);
                cout << "---------------------------" << endl;
            }
            pos = hashFunc(date, list->size);
            if (table[pos]->date == date) {
                cout << "---------------------------" << endl;
                table[pos]->PrintHuman();
            }
            else {
                while (table[pos]->date != date && counter < list->size) {
                    pos++; counter++;
                    if (pos >= list->size) pos = pos - list->size;
                }
                if (counter < list->size) table[pos]->PrintHuman();
                else cout << "Ошибка: дата не найдена" << endl;
            }
            break;
        case 10:
            flag = false;
            table = MethodChain(list);
            PrintHash(table, list->size, 2);
            cout << "Введите дату рождения: ";
            getline(cin, date); getline(cin, date);
            while (date.length() != 10) {
                cout << "Введите дату рождения: ";
                getline(cin, date);
            }
            pos = hashFunc(date, list->size);
            human = table[pos];
            while (!flag && human != nullptr) {
                if (human->date == date) flag = true;
                else human = human->next;
            }
            if (flag) human->PrintHuman();
            else cout << "Ошибка: дата не найдена" << endl;
            break;
        }

    }
}


int main() {
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    Menu();
    return 0;
}