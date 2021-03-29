#include "User.h"
#include <string.h>

FAS::User::User(const char* _name, AccessLevel aL)
{
    m_item_name = new char[512];
    strcpy(m_item_name, _name);
    accessLevel = aL;
}

FAS::User::User(FAS::User& copy)
{
    m_item_name = new char[512];
    strcpy(m_item_name, copy.m_item_name);
    accessLevel = copy.accessLevel;
}

FAS::User::User()
{
    m_item_name = new char[512];
}

FAS::User::~User()
{
    // delete[] name;
}

FAS::User::AccessLevel FAS::User::GetAccessLevel()
{
    return accessLevel;
}

void FAS::User::SetAccessLevel(AccessLevel setTo)
{
    accessLevel = setTo;
}