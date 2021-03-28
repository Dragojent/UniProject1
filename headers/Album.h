#pragma once
#include "Photo.h"
#include "MenuItem.h"
#include "myArray.h"

namespace FAS
{
    class Album : public MenuItem
    {
        public:
            Album(const char* name, myArray<Photo> _photos);
            Album(Album& copy);
            Album();
            ~Album();

            myArray<Photo> getPhotos();
            void run();

            Photo& operator[](const unsigned int index);
            Album& operator=(const Album& album);
        private:
            myArray<Photo> photos;
    };
}