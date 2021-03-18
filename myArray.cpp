#include "myArray.h"
#include <algorithm>
#include <iostream>
#include <iterator>

template<class T>
FAS::myArray<T>::myArray()
{
    content = new T[1];
    totalSize = 1;
    currentSize = 0;
}

template <class T>
FAS::myArray<T>::myArray(std::initializer_list<T> list)
{
    content = new T[list.size()];
    std::copy(list.begin(), list.end(), content);
    totalSize = list.size();
    currentSize = list.size();
}

template <class T>
void FAS::myArray<T>::push(T data)
{
    if (currentSize == totalSize)
    {
        T* tmp = new T[2 * totalSize];
        std::copy(content, content + currentSize, tmp);
        delete[] content;
        totalSize *= 2;
        content = tmp;
    }
    content[currentSize] = data;
    currentSize++;
}

template <class T>
T FAS::myArray<T>::pop()
{
    return content[--currentSize];
}

template <class T>
T FAS::myArray<T>::get(unsigned int index)
{
    return content[index];
}

template <class T>
int FAS::myArray<T>::getSize()
{
    return (currentSize - 1);
}

template <class T>
T* FAS::myArray<T>::getAll()
{
    return content;
}

template <class T>
void FAS::myArray<T>::print()
{
    for (int i = 0; i < currentSize; i++)
    {
        std::cout << content[i] << " ";
    }
    std::cout << std::endl;
}

template <class T>
FAS::myArray<T>::~myArray()
{
    delete[] content;
}


template class FAS::myArray<int>;