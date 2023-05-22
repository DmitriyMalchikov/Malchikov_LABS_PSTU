#include <map>
#include <iostream>

using namespace std;

// 1. ������� ������������� ��������� multimap
multimap<double, double> myMap;

// 2.��������� ��������� map ���������� ���� double
void fillMap() {
    // �������� ������� � myMap ����� ���� � ������� ������� pair<>, ���� � ������� ������ make_pair()
    myMap.insert(make_pair(3.2, 10.3));            // ������ ����
    myMap.insert(pair<double, double>(1.1, 5.2));  // ������ ����
    myMap.insert(make_pair(2.4, 4.7));             // � �.�.
    myMap.insert(pair<double, double>(4.7, 8.9));
}


// 3. ����� ������� �������������� � �������� � ����� ����������
double calculateMid() {
    double sum = 0;
    for (pair<double,double> it : myMap) { // ����������� �� ����� myMap ����� ��������
        sum += it.second;    // � ����� ���������� �������� ������� ��������
    }
    double mid = sum / myMap.size(); // ������� ��������������
    myMap.insert(pair<double, double>(mid, mid)); // ��������� � myMap
    return mid;
}

// 4. ����� �������� ������� �� ���������� � ������� ��
void removeInRange(double lower, double upper) {
    auto it = myMap.lower_bound(lower); // ���������� ����� �������
    auto end = myMap.upper_bound(upper); // ���������� ������ �������
    myMap.erase(it, end);               // ������� ��� � ����� �� ������
}

// 5. �������� � ������� �������� ����� ������������� � ������������ ��������
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
    cout << "������������ = " << max << endl;
    cout << "����������� = " << min << endl;
    cout << "����� = " << sum << endl;
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
    cout << "������� �������������� = " << mid << endl;
    for (pair<double,double> it : myMap) {
        cout << it.first << ": " << it.second << endl;
    }
    cout << "-----------" << endl;
    cout << "�������� ��������� � ������� �� 1.1 �� 3.2" << endl;
    removeInRange(1.1, 3.2);
    for (pair<double,double> it : myMap) {
        cout << it.first << ": " << it.second << endl;
    }
    cout << "-----------" << endl;
    return 0;
}

