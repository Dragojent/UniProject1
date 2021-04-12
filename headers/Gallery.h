#pragma once
#include "AbstractItem.h"
#include "myArray.h"
#include "Album.h"

namespace FAS
{
    class Gallery : public AbstractItem
    {
        public:
            Gallery(std::string name, myArray<Album*> albums);
            Gallery(Gallery& copy);
            Gallery();
            ~Gallery();

            void eraseAlbum(size_t index);
            size_t addAlbum(Album* album);
            myArray<Album*> filter(std::string key) const;
            myArray<Album*> albums() const;
            void sort();

            Album* operator[](const size_t index) const;
            Gallery& operator=(const Gallery& gallery);
            // friend std::istream& operator>>(std::istream& in, Gallery& sum);

        private:
            myArray<Album*> m_albums;
    };
    // std::istream& operator>>(std::istream& in, Gallery& sum);
}