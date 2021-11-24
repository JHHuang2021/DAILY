#include <bits/stdc++.h>

using namespace std;

void debugPrint() { cout << endl; }

template<typename Type, typename ...Types>
void debugPrint(const Type &arg, const Types &...args) {
    cout << arg << " ";
    debugPrint(args...);
}

int main() {
    std::string str("test message");
    debugPrint("Hello, Happy World!", 19260817, false, str);
    debugPrint("debug");
    return 0;
}