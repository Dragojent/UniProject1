#include "MenuItem.h"
#include <iostream>
#include <cstring>

FAS::MenuItem::MenuItem(MenuItem& copy)
{
    m_item_name = new char[1024]{};
    strcpy(m_item_name, copy.m_item_name);
    m_func = copy.m_func;
    ID = std::time(0);
}

FAS::MenuItem::MenuItem(const char* name, FAS::MenuItem::Func action)
{
    m_item_name = new char[1024]{};
    strcpy(m_item_name, name);
    m_func = action;
    ID = std::time(0);
}

FAS::MenuItem::MenuItem()
{
    m_item_name = new char[1024]{};
    ID = std::time(0);
}

FAS::MenuItem::~MenuItem()
{
    delete[] m_item_name;
}

void FAS::MenuItem::SetName(const char* name)
{
    strcpy(m_item_name, name);
}

char* FAS::MenuItem::GetName() const
{
    return m_item_name;
}

void FAS::MenuItem::PrintName() const
{
    std::cout << m_item_name << std::endl;;
}

std::time_t FAS::MenuItem::GetID()
{
    return ID;
}

void FAS::MenuItem::run()
{
    return m_func();
}

std::ostream& FAS::operator<<(std::ostream& out, const MenuItem& sum)
{
    sum.PrintName();
    return out;
}

FAS::MenuItem& FAS::MenuItem::operator=(const FAS::MenuItem& item)
{
    strcpy(m_item_name, item.m_item_name);
    m_func = item.m_func;
    return *this;
}

bool FAS::operator>(const MenuItem& mi1, const MenuItem& mi2)
{
    return (strcmp(mi1.m_item_name, mi2.m_item_name) > 0);
}

bool FAS::operator==(const MenuItem& mi1, const MenuItem& mi2)
{
    return (strcmp(mi1.m_item_name, mi2.m_item_name) == 0);
}

bool FAS::operator<(const MenuItem& mi1, const MenuItem& mi2)
{
    return (strcmp(mi1.m_item_name, mi2.m_item_name) < 0);
}
// std::ostream& operator<<(std::ostream& out, FAS::MenuItem& sum)
// {
//     sum.PrintName();
//     return out;
// }