#include <bits/stdc++.h>

using namespace std;
struct LinkRec {
    int data;
    LinkRec *next;
};

int main() {
    LinkRec *head, *rear, *p, *q;
    int n;
    cin >> n;
    head = p = new LinkRec;
    p->data = 0;
    for (int i = 1; i < n; i++) {
        q = new LinkRec;
        q->data = i;
        p->next = q;
        p = q;
    }
    p->next = head;
    q = head;
    while (q->next != q) {
        p = q->next;
        q = p->next;
        p->next = q->next;
        cout << q->data << "\t";
        delete q;
        q = p->next;
    }
    cout << endl << q->data << endl;
    return 0;
}