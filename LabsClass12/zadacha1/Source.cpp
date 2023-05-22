#include <map>
#include <iostream>

using namespace std;

// 1. Создаем ассоциативный контейнер multimap
multimap<double, double> myMap;

// 2.Заполняем контейнер map значениями типа double
void fillMap() {
    // Добавить элемент в myMap можно либо с помощью шаблона pair<>, либо с помощью метода make_pair()
    myMap.insert(make_pair(3.2, 10.3));            // первая пара
    myMap.insert(pair<double, double>(1.1, 5.2));  // вторая пара
    myMap.insert(make_pair(2.4, 4.7));             // и т.д.
    myMap.insert(pair<double, double>(4.7, 8.9));
}


// 3. Найти среднее арифметическое и добавить в конец контейнера
double calculateMid() {
    double sum = 0;
    for (pair<double,double> it : myMap) { // пробегаемся по всему myMap через итератор
        sum += it.second;    // к сумме прибавляем значение каждого элемента
    }
    double mid = sum / myMap.size(); // среднее арифметическое
    myMap.insert(pair<double, double>(mid, mid)); // вставляем в myMap
    return mid;
}

// 4. Найти элементы ключами из контейнера и удалить их
void removeInRange(double lower, double upper) {
    auto it = myMap.lower_bound(lower); // выставляем левую границу
    auto end = myMap.upper_bound(upper); // выставляем правую границу
    myMap.erase(it, end);               // удаляем все с левой по правую
}

// 5. Добавить к каждому элементу сумму максимального и минимального значения
void addToEach() {
    double min = 99999;
    double max = -99999;
    double sum;
    for (pair<double,double> it : myMap) {
        if (it.second > max) max = it.second;
        else {
            if (it.second < min) min = it.second;
        }
    }
    sum = max + min;
    for (auto& it : myMap) {
        it.second += sum;
    }
    cout << "Максимальное = " << max << endl;
    cout << "Минимальное = " << min << endl;
    cout << "Сумма = " << sum << endl;
}

int main() {
    setlocale(0, "");
    fillMap();
    for (pair<double,double> it : myMap) {
        cout << it.first << ": " << it.second << endl;
    }
    cout << "-----------" << endl;
    addToEach();
    for (pair<double,double> it : myMap) {
        cout << it.first << ": " << it.second << endl;
    }
    cout << "-----------" << endl;
    double mid = calculateMid();
    cout << "Среднее арифметическое = " << mid << endl;
    for (pair<double,double> it : myMap) {
        cout << it.first << ": " << it.second << endl;
    }
    cout << "-----------" << endl;
    cout << "Удаление элементов с ключами от 1.1 до 3.2" << endl;
    removeInRange(1.1, 3.2);
    for (pair<double,double> it : myMap) {
        cout << it.first << ": " << it.second << endl;
    }
    cout << "-----------" << endl;
    return 0;
}

