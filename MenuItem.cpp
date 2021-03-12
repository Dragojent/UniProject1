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

FAS::MenuItem::~MenuItem()
{
    delete[] m_item_name;
}

char* FAS::MenuItem::GetName()
{
    return m_item_name;
}

void FAS::MenuItem::PrintName()
{
    std::cout << FAS::MenuItem::GetName() << std::endl;
}

int FAS::MenuItem::run()
{
    return m_func();
}