#include "1287.hpp"
#include <iostream>
using namespace std;

int main(){
    BigIndexArray a;
    a[-922337203685477580] = 9223372036854775807;
    cout << a[-922337203685477580] << endl;
}