#include <cstring>
#include "Photo.h"

FAS::Photo::Photo(const char* name, const char* _content)
{
    strcpy(m_item_name, name);
    content = new char[256];
    strcpy(content, _content);
    people = myArray<char*>();
}

FAS::Photo::Photo(const char* name, const char* _content, myArray<char*> _people)
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
    people = myArray<char*>();
}

FAS::Photo::~Photo()
{
    delete[] content;
}