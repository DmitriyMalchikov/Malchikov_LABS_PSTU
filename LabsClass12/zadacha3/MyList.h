#pragma once
#include <iostream>
#include <map>
using namespace std;

template <typename T>
class MyList {
private:
    multimap<int, T> data;
public:
    void add(int key, T value) {
        data.insert(make_pair(key, value));
    }

    T& operator[](int index) {
        auto it = data.find(index);
        if (it == data.end()) {
            it = data.emplace(index, T());
        }
        return it->second;
    }

    int size() const {
        return data.size();
    }

    T operator*(const MyList<T>& other) const {
        T result = 1;
        for (int i = 0; i < size(); ++i) {
            result *= (*this)[i] * other[i];
        }
        return result;
    }

    void fillList()
    {
        add(0, 89);
        add(1, 29);
        add(2, 35);
        add(3, 10);
    }

    void calculateMid() {
        double sum = 0.0;
        for (auto& it : data) {
            sum += it.second;
        }
        double average = sum / size();
        cout << "Среднее арифметическое = " << average << endl;
        data.insert(make_pair(size(), average));
    }

    void removeElementsInRange(int lower, int upper) {
        auto it = data.lower_bound(lower);
        auto end = data.upper_bound(upper);
        data.erase(it, end);
    }

    void addToEach() {
        T min_value = data.begin()->second;
        T max_value = data.rbegin()->second;
        for (auto it = data.begin(); it != data.end(); it++) {
            min_value = min(min_value, it->second);
            max_value = max(max_value, it->second);
        }
        T sum = min_value + max_value;
        for (auto& p : data) {
            p.second += sum;
        }
        cout << "Максимальное = " << max_value << endl;
        cout << "Минимальное = " << min_value << endl;
        cout << "Сумма = " << sum << endl;
    }
};

