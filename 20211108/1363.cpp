#include "1363.hpp"

using namespace std;
struct node {
    int x = 1;
    int y = 1;
};

int main() {
    MyList<int> myList;
    myList.erase(0);
    for (int i = 1; i <= 100; i++)
        myList.push_back(i);

//    MyList<node> list1;
//    for (int i = 1; i <= 10; i++) {
//        node tmp;
//        tmp.x = i;
//        tmp.y = i + 1;
//        list1.push_front(tmp);
//    }
    return 0;
}
