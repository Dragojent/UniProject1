#include "CMenu.h"
#include <cstring>
#include <iostream>

FAS::CMenu::CMenu(const char* title, FAS::MenuItem* items, std::size_t count)
{
    m_title = new char[sizeof(FAS::MenuItem) * count + 256]{};
    strcpy(m_title, title);
    m_item = items;
    m_count = count;
}

FAS::CMenu::CMenu(CMenu& copy)
{
    m_title = new char[sizeof(FAS::MenuItem) * copy.m_count + 256]{};
    strcpy(m_title, copy.m_title);
    m_item = copy.m_item;
    m_count = copy.m_count;
    m_select = copy.m_select;
}

FAS::CMenu::~CMenu()
{
    delete[] m_title;
}

int FAS::CMenu::GetSelect()
{
    return m_select;
}

bool FAS::CMenu::IsRunning()
{
    return m_running;
}

char* FAS::CMenu::GetTitle()
{
    return m_title;
}  

size_t FAS::CMenu::GetNumberOfItems()
{
    return m_count;
}

FAS::MenuItem* FAS::CMenu::GetItems()
{
    return m_item;
}

void FAS::CMenu::print()
{
    for (int i = 0; i < m_count; i++)
    {
        m_item[i].PrintName();
    }
}

void FAS::CMenu::runCommand()
{
    std::cout << m_item[GetSelect()].run() << std::endl;
}

void FAS::CMenu::SetRunning(bool setTo)
{
    m_running = setTo;
}

void FAS::CMenu::SetSelect(int setTo)
{
    if (setTo < m_count && setTo >= 0)
        m_select = setTo;
}

void FAS::CMenu::MoveSelect(int shift)
{
    m_select += shift;
    if (m_select < 0)
        m_select += m_count;
    else if (m_select >= m_count)
        m_select -= m_count;
}