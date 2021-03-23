#include "MenuItem.h"
#include <iostream>
#include <cstring>

FAS::MenuItem::MenuItem(MenuItem& copy)
{
    m_item_name = new char[1024]{};
    strcpy(m_item_name, copy.GetName());
    m_func = copy.m_func;
}

FAS::MenuItem::MenuItem(const char* name, FAS::MenuItem::Func action)
{
    m_item_name = new char[1024]{};
    strcpy(m_item_name, name);
    m_func = action;
}

FAS::MenuItem::MenuItem()
{
    m_item_name = new char[1024]{};
}

FAS::MenuItem::~MenuItem()
{
    delete[] m_item_name;
}

char* FAS::MenuItem::GetName() const
{
    return m_item_name;
}

void FAS::MenuItem::PrintName() const
{
    std::cout << m_item_name << std::endl;
}

void FAS::MenuItem::run()
{
    return m_func();
}

FAS::MenuItem& FAS::MenuItem::operator=(const FAS::MenuItem &item)
{
    strcpy(m_item_name, item.m_item_name);
    m_func = item.m_func;
    return *this;
}

// std::ostream& operator<<(std::ostream& out, FAS::MenuItem& sum)
// {
//     sum.PrintName();
//     return out;
// }