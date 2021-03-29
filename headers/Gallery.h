#pragma once
#include "MenuItem.h"
#include "myArray.h"
#include "Album.h"

namespace FAS
{
    class Gallery : public MenuItem
    {
        public:
            Gallery(const char* name, myArray<Album> _albums);
            Gallery(Gallery& copy);
            Gallery();
            ~Gallery();

            myArray<Album> getAlbums();
            void run();
            void sort();
            void erase(unsigned int index);
            int add(Album album);
            myArray<Album> filter(const char* ex);

            Album& operator[](const unsigned int index);
            Gallery& operator=(const Gallery& gallery);
        private:
            myArray<Album> albums;
    };
}