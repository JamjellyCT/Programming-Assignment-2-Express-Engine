#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <vector>
#include <stdexcept>

template <typename T>
class ArrayStack {
private:
    std::vector<T> data;

public:
    void push(const T& value) {
        // TODO
        data.push_back(value);
        std::cout << "Pushed value " << value << std::endl;
    }

    void pop() {
        // TODO
        if (empty()) {
            std::cout << "Stack is empty, stack underflow." << std::endl;
            return;
        }
        T val = data.back();
        data.pop_back();
        std::cout << "Popped " << val << std::endl;
    }

    T top() const {
        // TODO
        if (empty()) {
            std::cout << "Stack is empty" << std::endl;
            return T();
        }
        return data.back();
    }

    bool empty() const {
        // TODO
        return data.empty();
    }

    int size() const {
        // TODO
        return data.size();
    }
};

#endif
