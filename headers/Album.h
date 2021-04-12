#pragma once
#include "Photo.h"
#include "AbstractItem.h"
#include "myArray.h"

namespace FAS
{
    class Album : public AbstractItem
    {
        public:
            Album(std::string name, myArray<Photo*> photos);
            Album(Album& copy);
            Album();
            ~Album();

            void erasePhoto(size_t index);
            size_t addPhoto(Photo* photo);
            myArray<Photo*> filter(std::string key) const;
            myArray<Photo*> photos() const;
            void sort();

            Photo* operator[](const size_t index) const;
            Album& operator=(const Album& album);
        private:
            myArray<Photo*> m_photos;
    };
}