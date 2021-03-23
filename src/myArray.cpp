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
FAS::myArray<T>::myArray(myArray<T> &copy)
{
    content = new T[copy.currentSize];
    std::copy(copy.content, copy.content + copy.currentSize, content);
    currentSize = copy.currentSize;
    totalSize = copy.totalSize;
}

template <class T>
unsigned int FAS::myArray<T>::push(T data)
{
    if (currentSize == totalSize)
        allocateMoreMemory();
    content[currentSize++] = data;
    return currentSize;
}

template <class T>
T FAS::myArray<T>::pop()
{
    if (currentSize == 0)
        throw "Array is empty";
    return content[--currentSize];
}

template <class T>
void FAS::myArray<T>::place(T data, unsigned int index)
{
    if (index >= currentSize)
        throw "Acces Error: out of bounds";
    if (currentSize == totalSize)
        allocateMoreMemory();
    currentSize++;
    for (int i = currentSize - 1; i > index; i--)
    {
        content[i] = content[i - 1];
    }
    content[index] = data;
}

template <class T>
int FAS::myArray<T>::getSize()
{
    return currentSize;
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
T& FAS::myArray<T>::operator[](const unsigned int index)
{
    if (index >= currentSize)
        throw "Acces Error: out of bounds";
    return content[index];
}

template <class T>
FAS::myArray<T>& FAS::myArray<T>::operator=(const FAS::myArray<T> &data)
{
    if (data.content == nullptr)
        throw "Access Error: null reference";
    std::copy(data.content, data.content + data.currentSize, content);
    currentSize = data.currentSize;
    totalSize = data.totalSize;
    return *this;
}

template <class T>
void FAS::myArray<T>::allocateMoreMemory()
{
    T* old = content;
    content = new T[totalSize*=2];
    std::copy(old, old + currentSize, content);
    delete[] old;
}


template class FAS::myArray<int>;
template class FAS::myArray<float>;
template class FAS::myArray<char>;
template class FAS::myArray<double>;
template class FAS::myArray<FAS::MenuItem>;