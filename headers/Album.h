#pragma once
#include "Photo.h"
#include "AbstractItem.h"
#include "myArray.h"

namespace FAS
{
    class Album : public AbstractItem
    {
        public:
            Album(const char* name, myArray<Photo> _photos);
            Album(Album& copy);
            Album();
            ~Album();

            unsigned int GetSize() const;
            myArray<Photo> GetItems();
            void run();
            void sort();
            void erase(unsigned int index);
            int add(Photo photo);
            myArray<Photo*> filter(const char* ex);

            Photo& operator[](const unsigned int index);
            Album& operator=(const Album& album);
        private:
            myArray<Photo> photos;
    };
}