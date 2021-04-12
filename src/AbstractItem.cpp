#include "AbstractItem.h"
#include <iostream>
#include <cstring>

size_t IDincrement = 0;

FAS::AbstractItem::AbstractItem(AbstractItem& copy) :
    m_name({}), m_ID(std::time(0) + IDincrement++)
{
    m_name = copy.name();
}

FAS::AbstractItem::AbstractItem(std::string name) :
    m_name({}), m_ID(std::time(0) + IDincrement++)
{
    m_name = name;
}

FAS::AbstractItem::AbstractItem() :
    m_name({}), m_ID(std::time(0) + IDincrement++) {}

FAS::AbstractItem::~AbstractItem() {} 

void FAS::AbstractItem::setName(std::string name)
{
    m_name = name;
}

std::string FAS::AbstractItem::name() const
{
    return m_name;
}

void FAS::AbstractItem::printName() const
{
    std::cout << m_name << std::endl;
}

size_t FAS::AbstractItem::ID() const
{
    return m_ID;
}

std::ostream& FAS::operator<<(std::ostream& out, const AbstractItem& sum)
{
    std::cout << sum.name();
    return out;
}

bool FAS::operator>(const AbstractItem& mi1, const AbstractItem& mi2)
{
    return (mi1.name() > mi2.name());
}

bool FAS::operator==(const AbstractItem& mi1, const AbstractItem& mi2)
{
    return (mi1.name() == mi2.name());
}

bool FAS::operator<(const AbstractItem& mi1, const AbstractItem& mi2)
{
    return (mi1.name() < mi2.name());
}

// std::ostream& operator<<(std::ostream& out, FAS::AbstractItem& sum)
// {
//     sum.PrintName();
//     return out;
// }