#ifndef INC_20211108_1287_HPP
#define INC_20211108_1287_HPP

#include <bits/stdc++.h>

class BigIndexArray {
private:
    std::unordered_map<long long, long long> array;
public:
    long long &operator[](const long long &index) {
        return array[index];
    }
};

#endif
