#pragma once
#include "MenuItem.h"
#include <initializer_list>

namespace FAS
{
    template <class T>
    class myArray {
    public:

        myArray(std::initializer_list<T> list);
        myArray();
        ~myArray();

        const T* begin();
        const T* end();
        void push(T data);
        void push(T data, unsigned int index);
        T pop();
        T get(unsigned int index);
        int getSize();
        T* getAll();
        void print();

    private:
       T *content = nullptr;
       unsigned int currentSize = 0;
       unsigned int totalSize = 0;
    };
}