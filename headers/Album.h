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

            void run();
        private:
            myArray<Photo> photos;
    };
}