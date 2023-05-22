#pragma once
#include <iostream>
using namespace std;

class Pair {
public:
    int first;
    double second;
    Pair(int, double);
    void print();
    bool operator<(const Pair& other) const {
        return first < other.first;
    }
    friend ostream& operator<<(ostream&, const Pair&); // перегруженный оператор вывода пары на экран
};

