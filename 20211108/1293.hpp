#ifndef INC_20211108_1293_HPP
#define INC_20211108_1293_HPP

class shared_ptr {
private:
    int *_ptr;
    int copy = 0;
public:
    shared_ptr(int *ptr) : _ptr(ptr) {
        copy = 0;
    }

    shared_ptr(const shared_ptr &ptr) : _ptr(ptr._ptr) {
        copy = 1;
    }

    shared_ptr() : _ptr(nullptr) {
        copy = 0;
    }

    ~shared_ptr() {
        if (_ptr != nullptr && copy == 0) {
            delete _ptr;
            _ptr = nullptr;
        }
    }

    shared_ptr &operator=(const shared_ptr &ptr) {
        if (this->_ptr == ptr._ptr)
            return *this;
        else {
            if (copy == 0)
                delete _ptr;
            _ptr = ptr._ptr;
            copy = 1;
            return *this;
        }
    }

    void reset() {
        if (copy == 0)
            delete _ptr;
        copy = 0;
        _ptr = nullptr;
    }

    void reset(int *&&ptr) {
        if (copy == 0)
            delete _ptr;
        copy = 0;
        _ptr = ptr;
    }

    int &operator*() {
        return *(_ptr);
    }

    int &operator*() const {
        return *(_ptr);
    }
};

#endif //INC_20211108_1293_HPP
