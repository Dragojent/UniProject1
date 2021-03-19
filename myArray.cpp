#include "MenuItem.h"
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
        T* old = content;
        content = new T[totalSize*=2];
        std::copy(old, old + currentSize, content);
        delete[] old;
    }
    content[currentSize++] = data;
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

template <class T>
T& FAS::myArray<T>::operator[](const int index)
{
    return content[index];
}


template class FAS::myArray<int>;
template class FAS::myArray<float>;
template class FAS::myArray<char>;
template class FAS::myArray<double>;
template class FAS::myArray<FAS::MenuItem>;