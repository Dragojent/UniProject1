#include "User.h"
#include <string.h>

FAS::User::User(std::string name, AccessLevel AL)
{
    m_name = name;
    m_accessLevel = AL;
}

FAS::User::User(FAS::User& copy)
{
    m_name = copy.name();
    m_accessLevel = copy.accessLevel();
}

FAS::User::User() :
    m_accessLevel(AccessLevel::user) {}

FAS::User::~User() {} 

FAS::User::AccessLevel FAS::User::accessLevel() const
{
    return m_accessLevel;
}

void FAS::User::SetAccessLevel(AccessLevel AL)
{
    m_accessLevel = AL;
}