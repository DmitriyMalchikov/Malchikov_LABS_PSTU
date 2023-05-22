#include <iostream>
#include <map>
#include "MyList.h"
using namespace std;



int main() {
    setlocale(0, "");
    MyList<int> list1;
    list1.fillList();
    for (int i = 0; i < list1.size(); ++i) {
        cout << list1[i] << " ";
    }
    cout << endl << "-----------" << endl;
    list1.addToEach();
    for (int i = 0; i < list1.size(); ++i) {
        cout << list1[i] << " ";
    }
    cout << endl << "-----------" << endl;
    list1.calculateMid();
    for (int i = 0; i < list1.size(); ++i) {
        cout << list1[i] << " ";
    }
    cout << endl << "-----------" << endl;
    cout << "Удаление элементов с ключами от 0 до 2" << endl;
    list1.removeElementsInRange(0, 2);
    for (int i = 0; i < list1.size(); ++i) {
        if (list1[i] != 0) {
            cout << list1[i] << " ";
        }
    }
    cout << endl << "-----------" << endl;
    return 0;
}
