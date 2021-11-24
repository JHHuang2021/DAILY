#include<iostream>
#include "Function.hpp"

using namespace std;

void generate(int seed);

int getLen();

int queryMin(int l, int r);

bool check(int index);

int main() {
    int seed, ans;//ans应当为最小值所在的下标
    cin >> seed;
    generate(seed);
    int min_ = queryMin(0, getLen() - 1);
    int head = 0, tail = getLen() - 1;
    while (head < tail) {
        if (min_ == queryMin(head, (head + tail) / 2))
            tail = (head + tail) / 2;
        else
            head = (head + tail) / 2 + 1;
    }
    ans = head;
    check(ans);
}