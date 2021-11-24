#include "1292.hpp"

int main() {
    Calendar c;
    c = Calendar("2010-01-01");
    cout << c.getday() << endl;
    cout << c << endl;
    cout << c.getday() << endl;
    cout << ++c << endl;
    cout << c.getday() << endl;
    cout << (c += 1) << endl;
    cout << c.getday() << endl;
    cout << (c -= 1) << endl;
    cout << c.getday() << endl;
    cout << --c << endl;
    cout << (c += 1) - (c -= 1) << endl;
    cout << c - c << endl;
    cout << (c -= 1) - (c += 1) << endl;

    cout << "!!!" << endl;
    int cc = 2;
    cout << (cc += 1) - (cc -= 1) << endl;
}
