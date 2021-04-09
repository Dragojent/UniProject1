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

FAS::myArray<FAS::Photo> FAS::Album::GetItems()
{
    return photos;
}

void FAS::Album::run()
{
    //CMenu
}

void FAS::Album::erase(unsigned int index)
{
    photos.erase(index);
}

int FAS::Album::add(Photo album)
{
    photos.push(album);
    return photos.getSize();
}

unsigned int FAS::Album::GetSize() const
{
    return photos.getSize();
}

FAS::myArray<FAS::Photo*> FAS::Album::filter(const char* ex)
{
    myArray<Photo*> tmparr{};
    for (FAS::Photo &photo : photos)
        if (strncmp(photo.GetName(), ex, strlen(ex)) == 0)
            tmparr.push(&photo);
    return tmparr;
}

void FAS::Album::sort()
{
    photos.sort();
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