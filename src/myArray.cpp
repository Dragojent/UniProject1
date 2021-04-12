#include "Gallery.h"
#include "Photo.h"
#include "Album.h"
#include "AbstractItem.h"
#include "MenuItem.h"
#include "myArray.h"
#include <algorithm>
#include <iostream>
#include <iterator>

template<class T>
FAS::myArray<T>::myArray() :
    m_content(new T[1]) {}

template <class T>
FAS::myArray<T>::myArray(std::initializer_list<T> list) :
    m_content(new T[list.size()]), m_totalSize(list.size()), m_currentSize(list.size())
{
    std::copy(list.begin(), list.end(), m_content);
}

template <class T>
FAS::myArray<T>::myArray(const myArray<T> &copy) :
    m_content(new T[copy.size()]), m_currentSize(copy.size()), m_totalSize(copy.capacity())
{
    std::copy(copy.begin(), copy.end(), m_content);
}

template <class T>
FAS::myArray<T>::~myArray()
{
    delete[] m_content;
}

template <class T>
size_t FAS::myArray<T>::push_back(T data)
{
    if (m_currentSize == m_totalSize)
        reserve();
    m_content[m_currentSize++] = data;
    return m_currentSize;
}

template <class T>
T FAS::myArray<T>::pop_back()
{
    if (m_currentSize == 0)
        throw "Array is empty";
    return m_content[--m_currentSize];
}

template <class T>
void FAS::myArray<T>::insert(T data, size_t index)
{
    if (index >= m_currentSize)
        throw "Access Error: out of bounds";
    if (m_currentSize == m_totalSize)
        reserve();
    m_currentSize++;
    for (int i = m_currentSize - 1; i > index; i--)
    {
        m_content[i] = m_content[i - 1];
    }
    m_content[index] = data;
}

template <class T>
T FAS::myArray<T>::erase(size_t index)
{
    if (index >= m_currentSize)
        throw "Access error: out of bounds";
    if (m_currentSize == 0)
        throw "Array is empty";
    swap(index, m_currentSize - 1);
    return m_content[--m_currentSize];
}

template <class T>
void FAS::myArray<T>::swap(int a, int b)
{
    T tmp = m_content[a];
    m_content[a] = m_content[b];
    m_content[b] = tmp;
}

template <class T>
void FAS::myArray<T>::clear()
{
    delete[] m_content;
    m_content = new T[1];
    m_currentSize = 0;
    m_totalSize = 1;
}

template <class T>
bool FAS::myArray<T>::empty() const
{
    return !m_currentSize;
}

template <class T>
size_t FAS::myArray<T>::size() const
{
    return m_currentSize;
}

template <class T>
size_t FAS::myArray<T>::capacity() const
{
    return m_totalSize;
}

template <class T>
T* FAS::myArray<T>::begin() const
{
    return &m_content[0];
}

template <class T>
T* FAS::myArray<T>::end() const
{
    return &m_content[m_currentSize];
}

template <class T>
T& FAS::myArray<T>::operator[](const size_t index) const
{
    if (index >= m_currentSize)
        throw "Access Error: out of bounds";
    return m_content[index];
}

template <class T>
FAS::myArray<T>& FAS::myArray<T>::operator=(const FAS::myArray<T> &data)
{
    if (data.m_content == nullptr)
        throw "Access Error: null reference";
    delete[] m_content;
    m_content = new T[data.size()];
    std::copy(data.begin(), data.end(), m_content);
    m_currentSize = data.size();
    m_totalSize = data.capacity();
    return *this;
}

template <class T>
size_t FAS::myArray<T>::reserve()
{
    T* old = m_content;
    m_content = new T[m_totalSize*=2];
    std::copy(old, old + m_currentSize, m_content);
    delete[] old;
    return m_totalSize;
}

template class FAS::myArray<int>;
template class FAS::myArray<float>;
template class FAS::myArray<char>;
template class FAS::myArray<double>;
template class FAS::myArray<char*>;
template class FAS::myArray<size_t>;
template class FAS::myArray<FAS::Photo>;
template class FAS::myArray<FAS::Photo*>;
template class FAS::myArray<FAS::Album>;
template class FAS::myArray<FAS::Album*>;
template class FAS::myArray<FAS::Gallery>;
template class FAS::myArray<FAS::User>;
template class FAS::myArray<FAS::User*>;
template class FAS::myArray<FAS::MenuItem>;