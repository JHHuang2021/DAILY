#ifndef Wrapper_CPP_Wrapper_HPP
#define Wrapper_CPP_Wrapper_HPP

#include <string>

struct Wrapper {
    // todo: add definitions here
    void (*foo)(std::string str);

    void (*before)();

    void (*after)();

    Wrapper(void foo(std::string str), void before(), void after()) {
        this->foo = foo;
        this->before = before;
        this->after = after;
    }
};

// todo: add definition for link list
std::vector<Wrapper *> func;

Wrapper *create(void foo(std::string str), void before(), void after()) {
    auto *tmp = new Wrapper(foo, before, after);
    func.push_back(tmp);
    return tmp;
}

void remove(Wrapper *&p) {
    func.erase(std::find(func.begin(), func.end(), p));
    delete p;
    p = nullptr;
}

void run(Wrapper *p, std::string str) {
    p->before();
    p->foo(str);
    p->after();
}

void destroy() {
    for (auto &i: func)
        if (i != nullptr) {
            delete i;
            i = nullptr;
        }
}

#endif //Wrapper_CPP_Wrapper_HPP