#include <cstring>
#include "Album.h"

FAS::Album::Album(std::string name, myArray<Photo*> photos) :
    m_photos({})
{
    m_name = name;
    m_photos = photos;
}

FAS::Album::Album(Album& copy) :
    m_photos({})
{
    m_name = copy.name();
    m_photos = copy.photos();
}

FAS::Album::Album() :
    m_photos({}) {}

FAS::Album::~Album() {}

FAS::myArray<FAS::Photo*> FAS::Album::photos() const
{
    return m_photos;
}

void FAS::Album::erasePhoto(size_t index)
{
    m_photos.erase(index);
}

size_t FAS::Album::addPhoto(Photo* photo)
{
    m_photos.push_back(photo);
    return m_photos.size();
}

FAS::myArray<FAS::Photo*> FAS::Album::filter(std::string key) const
{
    myArray<Photo*> tmparr{};
    for (auto photo : m_photos)
        if (photo->name() == key)
            tmparr.push_back(photo);
    return tmparr;
}

void FAS::Album::sort()
{
    for (int i = 0; i < m_photos.size() - 1; i++)
        for (int j = 0; j < m_photos.size() - i - 1; j++)
            if (m_photos[j] > m_photos[j + 1])
                m_photos.swap(j, j + 1);
}

FAS::Photo* FAS::Album::operator[](const size_t index) const
{
    return m_photos[index];
}

FAS::Album& FAS::Album::operator=(const Album& album)
{
    m_name = album.name();
    m_photos = album.photos();
    return *this;
}