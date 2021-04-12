#include <cstring>
#include "Gallery.h"

FAS::Gallery::Gallery(std::string name, myArray<Album*> albums) :
    m_albums({})
{
    m_name = name;
    m_albums = albums;
}

FAS::Gallery::Gallery(Gallery& copy) :
    m_albums({})
{
    m_name = copy.name();
    m_albums = copy.albums();
}

FAS::Gallery::Gallery() :
    m_albums({}) {}

FAS::Gallery::~Gallery() {}

FAS::myArray<FAS::Album*> FAS::Gallery::albums() const
{
    return m_albums;
}

void FAS::Gallery::sort()
{
    for (int i = 0; i < m_albums.size() - 1; i++)
        for (int j = 0; j < m_albums.size() - i - 1; j++)
            if (m_albums[j] > m_albums[j + 1])
                m_albums.swap(j, j + 1);
}

void FAS::Gallery::eraseAlbum(size_t index)
{
    m_albums.erase(index);
}

size_t FAS::Gallery::addAlbum(Album* album)
{
    m_albums.push_back(album);
    return m_albums.size();
}

FAS::myArray<FAS::Album*> FAS::Gallery::filter(std::string key) const
{
    myArray<Album*> tmparr{};
    for (auto album : m_albums)
        if (m_name == key)
            tmparr.push_back(album);
    return tmparr;
}

FAS::Album* FAS::Gallery::operator[](const size_t index) const
{
    return m_albums[index];
}

FAS::Gallery& FAS::Gallery::operator=(const Gallery& gallery)
{
    m_name = gallery.name();
    m_albums = gallery.albums();
    return *this;
}

// std::istream& FAS::operator>>(std::istream& in, FAS::Gallery& sum)
// {
//     FAS::Album tmp{};
//     std::string tmpname{};
//     in >> tmpname;
//     tmp.setName(tmpname);
//     sum.addAlbum(&tmp);
//     return in;
// }