#include "AbstractItem.h"
#include <iostream>
#include <cstring>

FAS::AbstractItem::AbstractItem(AbstractItem& copy)
{
    m_item_name = new char[1024]{};
    strcpy(m_item_name, copy.m_item_name);
    ID = std::time(0);
}

FAS::AbstractItem::AbstractItem(const char* name)
{
    m_item_name = new char[1024]{};
    strcpy(m_item_name, name);
    ID = std::time(0);
}

FAS::AbstractItem::AbstractItem()
{
    m_item_name = new char[1024]{};
    ID = std::time(0);
}

FAS::AbstractItem::~AbstractItem()
{
    delete[] m_item_name;
}

void FAS::AbstractItem::SetName(const char* name)
{
    strcpy(m_item_name, name);
}

char* FAS::AbstractItem::GetName() const
{
    return m_item_name;
}

void FAS::AbstractItem::PrintName() const
{
    std::cout << m_item_name << std::endl;
}

unsigned long FAS::AbstractItem::GetID()
{
    return ID;
}

unsigned int FAS::AbstractItem::GetSize() const
{
    return 1;
}

std::ostream& FAS::operator<<(std::ostream& out, const AbstractItem& sum)
{
    std::cout << sum.GetName();
    return out;
}

FAS::AbstractItem& FAS::AbstractItem::operator=(const FAS::AbstractItem& item)
{
    strcpy(m_item_name, item.m_item_name);
    return *this;
}

bool FAS::operator>(const AbstractItem& mi1, const AbstractItem& mi2)
{
    return (strcmp(mi1.m_item_name, mi2.m_item_name) > 0);
}

bool FAS::operator==(const AbstractItem& mi1, const AbstractItem& mi2)
{
    return (strcmp(mi1.m_item_name, mi2.m_item_name) == 0);
}

bool FAS::operator<(const AbstractItem& mi1, const AbstractItem& mi2)
{
    return (strcmp(mi1.m_item_name, mi2.m_item_name) < 0);
}
// std::ostream& operator<<(std::ostream& out, FAS::AbstractItem& sum)
// {
//     sum.PrintName();
//     return out;
// }