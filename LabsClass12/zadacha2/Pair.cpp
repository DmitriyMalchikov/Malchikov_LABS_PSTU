#include "Pair.h"
Pair::Pair(int f, double s)
{
    first = f;
    second = s;
}

void Pair::print()
{
    cout << first << ":" << second << endl;
}

ostream& operator<<(ostream& os, const Pair& p) {
    os << p.first << ":" << p.second;
    return os;
}