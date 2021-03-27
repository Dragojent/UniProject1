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

            void run();
        private:
            myArray<Album> albums;
    };
}