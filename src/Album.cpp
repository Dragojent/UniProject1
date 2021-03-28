#include <cstring>
#include "Album.h"

FAS::Album::Album(const char* name, myArray<Photo> _photos)
{
    strcpy(m_item_name, name);
    photos = _photos;
}

FAS::Album::Album(Album& copy)
{
    strcpy(m_item_name, copy.m_item_name);
    photos = copy.photos;
}

FAS::Album::Album()
{
    photos = myArray<Photo>();
}

FAS::Album::~Album()
{
    // delete[] m_item_name;
}

FAS::myArray<FAS::Photo> FAS::Album::getPhotos()
{
    return photos;
}

void FAS::Album::run()
{
    //CMenu
}

FAS::Photo& FAS::Album::operator[](const unsigned int index)
{
    return photos[index];
}

FAS::Album& FAS::Album::operator=(const Album& album)
{
    strcpy(m_item_name, album.m_item_name);
    photos = album.photos;
    return *this;
}