#ifndef MYARRAY_H
#define MYARRAY_H

#include <iostream>
#include <initializer_list>

namespace FAS
{
    template <class T>
    class myArray 
    {
        public:
            myArray();
            myArray(std::initializer_list<T> list);
            myArray(const myArray &copy);
            ~myArray();

            size_t push_back(T data);
            T pop_back();
            void insert(T data, size_t index);
            T erase(size_t index);
            void swap(int a, int b);
            void clear();

            bool empty() const;
            size_t size() const;
            size_t capacity() const;
            T* begin() const;
            T* end() const;

            T& operator[](const size_t index) const;
            myArray& operator=(const myArray &data);

        private:
            size_t reserve();
            T *m_content;
            size_t m_totalSize;
            size_t m_currentSize;
    };
}

#endif