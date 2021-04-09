#pragma once
#include "AbstractItem.h"
#include "myArray.h"
#include "Album.h"

namespace FAS
{
    class Gallery : public AbstractItem
    {
        public:
            Gallery(const char* name, myArray<Album> _albums);
            Gallery(Gallery& copy);
            Gallery();
            ~Gallery();

            unsigned int GetSize() const;
            myArray<Album> GetItems();
            void run();
            void sort();
            void erase(unsigned int index);
            int add(Album album);
            myArray<Album*> filter(const char* ex);

            Album& operator[](const unsigned int index);
            Gallery& operator=(const Gallery& gallery);
            friend std::istream& operator>>(std::istream& in, Gallery& sum);

        private:
            myArray<Album> albums;
    };
    std::istream& operator>>(std::istream& in, Gallery& sum);
}