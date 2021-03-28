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

FAS::myArray<FAS::Album> FAS::Gallery::getAlbums()
{
    return albums;
}

void FAS::Gallery::run()
{
    //CMenu
}

FAS::Album& FAS::Gallery::operator[](const unsigned int index)
{
    return albums[index];
}

FAS::Gallery& FAS::Gallery::operator=(const Gallery& gallery)
{
    strcpy(m_item_name, gallery.m_item_name);
    albums = gallery.albums;
    return *this;
}