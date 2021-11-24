#ifndef INC_20211108_1363_HPP
#define INC_20211108_1363_HPP

#include <bits/stdc++.h>

template<typename ValueType>
struct Node {
    ValueType value;
    Node<ValueType> *previous;
    Node<ValueType> *next;

    Node(const ValueType &val) : value(val), next(nullptr), previous(nullptr) {}

    Node() : next(nullptr), previous(nullptr) {}

};

template<typename ValueType>
class MyList {
private:
    Node<ValueType> *head;
    Node<ValueType> *tail;
    int the_size = 0;

public:
    MyList() : head(new Node<ValueType>()), tail(new Node<ValueType>()) {
        tail->previous = head;
        head->next = tail;
    }

    MyList(MyList &&obj) noexcept {
        head = new Node<ValueType>(), tail = new Node<ValueType>();
        head->next = obj.head->next;
        obj.head->next->previous = head;
        tail->previous = obj.tail->previous;
        obj.tail->previous->next = tail;
        this->the_size = obj.the_size;
        obj.head->next = obj.tail;
        obj.tail->previous = obj.head;
        obj.the_size = 0;
    }

    MyList(const MyList &obj)
            : head(new Node<ValueType>()), tail(new Node<ValueType>()) {
        tail->previous = head;
        head->next = tail;
        for (Node<ValueType> *iter = obj.head->next; iter != obj.tail; iter = iter->next)
            push_back(iter->value);
    }

    ~MyList() {
        clear();
        delete head;
        delete tail;
    }

    void push_back(const ValueType &value) {
        Node<ValueType> *tmp = new Node<ValueType>(value);
        tail->previous->next = tmp;
        tmp->previous = tail->previous;
        tail->previous = tmp;
        tmp->next = tail;
        the_size++;
    }

    void pop_back() {
        if (empty())
            return;
        else {
            Node<ValueType> *tmp = tail->previous;
            tmp->previous->next = tail;
            tail->previous = tmp->previous;
            delete tmp;
            the_size--;
        }
    }

    void push_front(const ValueType &value) {
        Node<ValueType> *tmp = new Node<ValueType>(value);
        tmp->next = head->next;
        head->next->previous = tmp;
        tmp->previous = head;
        head->next = tmp;
        the_size++;
    }

    void pop_front() {
        if (empty())
            return;
        else {
            Node<ValueType> *tmp = head->next;
            head->next = tmp->next;
            tmp->next->previous = head;
            delete tmp;
            the_size--;
        }
    }

    ValueType &front() const { return head->next->value; }

    ValueType &back() const { return tail->previous->value; }

    void insert(const int &index, const ValueType &value) {
        Node<ValueType> *tmp = head, *in = new Node<ValueType>(value);
        for (int i = 0; i < index; i++) tmp = tmp->next;
        in->next = tmp->next;
        in->previous = tmp;
        tmp->next->previous = in;
        tmp->next = in;
        the_size++;
    }

    void erase(const int &index) {
        Node<ValueType> *tmp = head;
        for (int i = 0; i <= index; i++) tmp = tmp->next;
        tmp->previous->next = tmp->next;
        tmp->next->previous = tmp->previous;
        delete tmp;
        the_size--;
    }

    int size() const { return the_size; }

    bool empty() const { return the_size == 0; }

    void clear() {
        while (!empty()) {
            pop_back();
        }
    }

    void link(MyList obj) {
        tail->previous->next = obj.head->next;
        obj.head->next->previous = tail->previous;
        obj.tail->previous->next = tail;
        tail->previous = obj.tail->previous;
        the_size += obj.the_size;
        obj.the_size = 0;
    }

    MyList cut(const int &index) {
        MyList<ValueType> new_list;
        Node<ValueType> *tmp = head;
        for (int i = 0; i < index; i++)
            tmp = tmp->next;
        new_list.head->next = tmp->next;
        tmp->next->previous = new_list.head;
        tail->previous->next = new_list.tail;
        new_list.tail->previous = tail->previous;
        tmp->next = tail;
        tail->previous = tmp;
        new_list.the_size = the_size - (index);
        the_size = index;
        return new_list;
    }
};

#endif //INC_20211108_1363_HPP
