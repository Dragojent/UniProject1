#include <cstring>
#include "Gallery.h"

FAS::Gallery::Gallery(const char* name, myArray<Album> _albums)
{
    strcpy(m_item_name, name);
    albums = _albums;
}

FAS::Gallery::Gallery(Gallery& copy)
{
    strcpy(m_item_name, copy.m_item_name);
    albums = copy.albums;
}

FAS::Gallery::Gallery()
{
    albums = myArray<Album>();
}

FAS::Gallery::~Gallery()
{
    // delete[] m_item_name;
}

void FAS::Gallery::run()
{
    //CMenu
}