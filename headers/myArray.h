#pragma once

#include <iostream>
#include "AbstractItem.h"
#include <initializer_list>

namespace FAS
{
    template <class T>
    class myArray {
    public:

        myArray(std::initializer_list<T> list);
        myArray(const myArray &copy);
        myArray();
        ~myArray();

        unsigned int push(T data);
        void place(T data, unsigned int index);
        T pop();
        int getSize() const;
        void print();
        void swap(int a, int b);
        void sort();
        T erase(unsigned int index);

        T* begin();
        T* end();

        T& operator[](const unsigned int index);
        myArray& operator=(const myArray &data);

    private:
        void allocateMoreMemory();
        T *content = nullptr;
        unsigned int currentSize = 0;
        unsigned int totalSize = 0;
    };
}