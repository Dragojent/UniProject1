#include <cstring>
#include "Photo.h"

FAS::Photo::Photo(const char* name, const char* _content)
{
    strcpy(m_item_name, name);
    content = new char[256];
    strcpy(content, _content);
    people = myArray<User>();
}

FAS::Photo::Photo(const char* name, const char* _content, myArray<User> _people)
{
    strcpy(m_item_name, name);
    content = new char[256];
    strcpy(content, _content);
    people = _people;
}

FAS::Photo::Photo(Photo& copy)
{
    strcpy(m_item_name, copy.m_item_name);
    content = new char[256];
    strcpy(content, copy.content);
    people = copy.people;
}

FAS::Photo::Photo()
{
    content = new char[256];
    people = myArray<User>();
}

FAS::Photo::~Photo()
{
    delete[] content;
}

void FAS::Photo::View()
{
    std::cout << content << std::endl;
}

FAS::myArray<FAS::User> FAS::Photo::GetPeople()
{
    return people;
}

void FAS::Photo::erase(unsigned int index)
{
    people.erase(index);
}

int FAS::Photo::add(User user)
{
    people.push(user);
    return people.getSize();
}

FAS::myArray<FAS::User> FAS::Photo::filter(const char* ex)
{
    myArray<User> tmparr{};
    for (FAS::User user : people)
    {
        if (strncmp(user.GetName(), ex, strlen(ex)) == 0)
        {
            tmparr.push(user);
        }
    }
    return tmparr;
}

void FAS::Photo::Sort()
{
    people.sort();
}

FAS::User& FAS::Photo::operator[](const unsigned int index)
{
    return people[index];
}

FAS::Photo& FAS::Photo::operator=(const Photo& photo)
{
    strcpy(m_item_name, photo.m_item_name);
    strcpy(content, photo.content);
    people = photo.people;
    return *this;
}