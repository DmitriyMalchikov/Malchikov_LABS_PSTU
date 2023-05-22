#include <iostream>
#include <map>
#include "Pair.h"
using namespace std;


// 1. ������� ������������� ��������� multimap
multimap<Pair,Pair> myMap;

// 2.��������� ��������� map ���������� ���� Pair
void fillMap() {
    Pair p1(2, 10.17);
    Pair p2(4, 28.58);
    Pair p3(10, 31.95);
    myMap.insert(make_pair(p2, p1));
    myMap.insert(make_pair(p3, p2));
    myMap.insert(make_pair(p1, p3));
}

//3. ����� ������� �������������� � �������� � ���������
void calculateMid() {
    // ���������� ��� �������� �����
    int count1 = 0;
    double sum1 = 0.0;
    int count2 = 0;
    double sum2 = 0.0;

    // ������� �����
    for (auto& it : myMap) {
        count1 += it.first.first;
        sum1 += it.first.second;
        count2 += it.second.first;
        sum2 += it.second.second;
    }

    // ������� ������� ��������������
    int average1 = count1 / myMap.size();
    double average2 = sum1 / myMap.size();
    int average3 = count2 / myMap.size();
    double average4 = sum2 / myMap.size();
    cout << "������� �������������� = " << average1 << ", " << average2 << ", " << average3 << ", " << average4 << endl;
    // ��������� ������� �������������� � ����� multimap
    myMap.insert(std::make_pair(Pair(average1, average2), Pair(average3, average4)));
}

// 4. ������� �������� �� ��������� �� �����
void removeElementsInRange(Pair lower, Pair upper)
{
    auto startIt = myMap.lower_bound(lower);
    auto endIt = myMap.upper_bound(upper);

    myMap.erase(startIt, endIt);
}

// 5. �������� � ������� �������� ����� ������������� � ������������ ��������
void addToEach() {
    double min1 = 99999 ,min2 = 99999;
    double max1 = -99999 ,max2 = -99999;
    double sum1,sum2;
    for (auto& it : myMap) {
        if (it.second.first > max1) max1 = it.second.first;
        else {
            if (it.second.first < min1) min1 = it.second.first;
        }
        if (it.second.second > max2) max2 = it.second.second;
        else {
            if (it.second.second < min2) min2 = it.second.second;
        }
    }
    sum1 = max1 + min1;
    sum2 = max2 + min2;
    for (auto& it : myMap) {
        it.second.first += sum1;
        it.second.second += sum2;
    }
    cout << "������������ 1 = " << max1 << endl;
    cout << "����������� 1 = " << min1 << endl;
    cout << "����� 1 = " << sum1 << endl;
    cout << "������������ 2 = " << max2 << endl;
    cout << "����������� 2 = " << min2 << endl;
    cout << "����� 2 = " << sum2 << endl;
}

int main() {
    setlocale(0, "");
    fillMap();
    for (auto& it : myMap) {
        std::cout << it.first << " => " << it.second << std::endl;
    }
    cout << endl;
    addToEach();
    for (auto& it : myMap) {
        std::cout << it.first << " => " << it.second << std::endl;
    }
    cout << endl;
    calculateMid();
    for (auto& it : myMap) {
        std::cout << it.first << " => " << it.second << std::endl;
    }
    cout << endl;
    cout << "�������� ��������� � ������� �� (2,0) �� (4,0)" << endl;
    removeElementsInRange(Pair(2, 0.0), Pair(4, 0.0));
    for (auto& it : myMap) {
        std::cout << it.first << " => " << it.second << std::endl;
    }
    cout << endl;
    return 0;
}