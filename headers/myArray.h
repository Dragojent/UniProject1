#pragma once
#include <iostream>
#include "MenuItem.h"
#include <initializer_list>

namespace FAS
{
    template <class T>
    class myArray {
    public:

        myArray(std::initializer_list<T> list);
        myArray(myArray &copy);
        myArray();
        ~myArray();

        const T* begin();
        const T* end();
        unsigned int push(T data);
        void place(T data, unsigned int index);
        T pop();
        int getSize();
        void print();

        T& operator[](const unsigned int index);
        myArray& operator=(const myArray &data);

    private:
        void allocateMoreMemory();
        T *content = nullptr;
        unsigned int currentSize = 0;
        unsigned int totalSize = 0;
    };
}