#pragma once
#include "CMenu.h"
#include "Gallery.h"
#include <iostream>

namespace FAS
{
    class GalleryMenu : public CMenu
    {
        public:
            GalleryMenu(const char* name, Gallery& _gallery);
            GalleryMenu(GalleryMenu& menu);
            GalleryMenu();
            ~GalleryMenu();

            void print();
            void Start();

        private:
            // Gallery* gallery;
    };
}