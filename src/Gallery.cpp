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

unsigned int FAS::Gallery::GetSize() const
{
    return albums.getSize();
}

FAS::myArray<FAS::Album> FAS::Gallery::GetItems()
{
    return albums;
}

void FAS::Gallery::run()
{
    
}

void FAS::Gallery::sort()
{
    albums.sort();
}

void FAS::Gallery::erase(unsigned int index)
{
    albums.erase(index);
}

int FAS::Gallery::add(Album album)
{
    albums.push(album);
    return albums.getSize();
}

FAS::myArray<FAS::Album*> FAS::Gallery::filter(const char* ex)
{
    myArray<Album*> tmparr{};
    for (FAS::Album &album : albums)
        if (strncmp(album.GetName(), ex, strlen(ex)) == 0)
            tmparr.push(&album);
    return tmparr;
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

// std::istream& FAS::operator>>(std::istream& in, FAS::Gallery& sum)
// {
//     FAS::Album tmp{};
//     char* tmpname{};
//     in >> tmpname;
//     tmp.SetName(tmpname);
//     sum.add(tmp);
//     return in;
// }