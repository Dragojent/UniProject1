#include "CMenu.h"
#include <conio.h> 
#include <cstring>
#include <iostream>

FAS::CMenu::CMenu(const char* title, FAS::myArray<FAS::MenuItem> items)
{
    m_title = new char[sizeof(FAS::MenuItem) * items.size() + 256]{};
    strcpy(m_title, title);
    m_item = items;
}

FAS::CMenu::CMenu(CMenu& copy)
{
    m_title = new char[sizeof(FAS::MenuItem) * copy.GetItems().size() + 256]{};
    strcpy(m_title, copy.m_title);
    m_item = copy.m_item;
    m_select = copy.m_select;
}

FAS::CMenu::CMenu()
{
    m_title = new char[4096];
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
    return m_item.size();
}

FAS::myArray<FAS::MenuItem> FAS::CMenu::GetItems()
{
    return m_item;
}

void FAS::CMenu::print()
{
    for (int i = 0; i < m_item.size(); i++)
    {
        if (i == m_select)
        {
            std::cout << ">";
        }
        m_item[i].PrintName();
    }
}

void FAS::CMenu::Start()
{
    m_select = 0;
    m_running = 1;
    while (m_running)
    {
        system("cls");
        this->print();
        char input{};
        input = getch();
        switch (input)
        {
        case 's':
            this->MoveSelect(1);
            break;
        
        case 'w':
            this->MoveSelect(-1);
            break;

        case 27:
            this->SetRunning(false);
            break;

        case 32:
            system("cls");
            // this->runCommand();
            break;

        default:
            break;
        }
    }
}

// void FAS::CMenu::runCommand()
// {
//     m_item[m_select].run();
// }

void FAS::CMenu::SetRunning(bool setTo)
{
    m_running = setTo;
}

void FAS::CMenu::SetSelect(int setTo)
{
    if (setTo < m_item.size() && setTo >= 0)
        m_select = setTo;
}

void FAS::CMenu::MoveSelect(int shift)
{
    m_select += shift;
    if (m_select < 0)
        m_select += m_item.size();
    else if (m_select >= m_item.size())
        m_select -= m_item.size();
}