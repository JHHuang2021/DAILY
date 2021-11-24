#include <iostream>

using namespace std;

struct Node {
    Node *next = nullptr;
    int value = 0;

    Node() {}

    Node(int value) { this->value = value; }
};

struct LinkedList {
    Node *head;
    int len;

    void initialize() {
        head = new Node;
        Node *tail = head;
        int m;
        cin >> m;
        len = m;
        for (int i = 1; i <= m; i++) {
            tail->next = new Node;
            cin >> tail->next->value;
            tail = tail->next;
        }
    }

    void insert(int i, int x) {
        Node *tmp = head;
        for (int k = 1; k <= i; k++)
            tmp = tmp->next;
        Node *ins = new Node(x);
        ins->next = tmp->next;
        tmp->next = ins;

        len++;
    }

    void erase(int i) {
        Node *tmp = head;
        for (int k = 1; k < i; k++)
            tmp = tmp->next;
        Node *del = tmp->next;
        tmp->next = del->next;
        delete del;

        len--;
    }

    void swap() {
        Node *tmp1 = head->next, *tmp2 = tmp1->next;
        for (int i = 1; i <= len; i += 2) {
            int tmp = tmp1->value;
            tmp1->value = tmp2->value;
            tmp2->value = tmp;
            if (tmp2->next == nullptr || tmp2->next->next == nullptr)
                break;
            else {
                tmp1 = tmp2->next;
                tmp2 = tmp1->next;
            }
        }
    }

    void cut(int i) {
        while (len > i) {
            erase(i + 1);
        }
    }

    int query(int i) {
        Node *tmp = head;
        for (int k = 1; k <= i; k++)
            tmp = tmp->next;
        return tmp->value;
    }

    int size() {
        return len;
    }

    void print() {
        Node *tmp = head->next;
        while (tmp->next != nullptr) {
            cout << tmp->value << " ";
            tmp = tmp->next;
        }
        cout << tmp->value << endl;
    }

    void freeMemory() {
        while (len)
            erase(1);
        delete head;
    }
};

int main() {
    LinkedList l;
    int n, op, i, x;
    l.initialize();
    cin >> n;
    while (n--) {
        cin >> op;
        if (op == 0) {
            cin >> i >> x;
            l.insert(i, x);
        } else if (op == 1) {
            cin >> i;
            l.erase(i);
        } else if (op == 2) {
            l.swap();
        } else if (op == 3) {
            cin >> i;
            l.cut(i);
        } else if (op == 4) {
            cin >> i;
            cout << l.query(i) << endl;
        } else if (op == 5) {
            cout << l.size() << endl;
        } else {
            l.print();
        }
    }
    l.freeMemory();
    return 0;
}