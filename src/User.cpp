#include "User.h"
#include <string.h>

FAS::User::User(const char* _name, AccessLevel aL)
{
    name = new char[512];
    strcpy(name, _name);
    accessLevel = aL;
}

FAS::User::User(FAS::User& copy)
{
    name = new char[512];
    strcpy(name, copy.name);
    accessLevel = copy.accessLevel;
}

FAS::User::User()
{
    name = new char[512];
}

FAS::User::~User()
{
    delete[] name;
}

FAS::User::AccessLevel FAS::User::GetAccessLevel()
{
    return accessLevel;
}

char* FAS::User::GetName()
{
    return name;
}

void FAS::User::SetAccessLevel(AccessLevel setTo)
{
    accessLevel = setTo;
}

void FAS::User::SetName(const char* setTo)
{
    strcpy(name, setTo);
}

FAS::User& FAS::User::operator=(const User& user)
{
    strcpy(name, user.name);
    accessLevel = user.accessLevel;
    return *this;
}

std::ostream& FAS::operator<<(std::ostream& out, const FAS::User& sum)
{
    std::cout << sum.name;
    return out;
}