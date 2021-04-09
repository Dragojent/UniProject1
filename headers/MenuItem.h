#pragma once

#include "myArray.h"
#include "AbstractItem.h"

namespace FAS
{
    class MenuItem
    {
        public:
            MenuItem(AbstractItem& _item);
            MenuItem(MenuItem& copy);
            MenuItem();
            ~MenuItem();

            void run();
            void PrintName();

            MenuItem& operator=(const MenuItem& _item);
            AbstractItem& operator[](const unsigned int index);
            friend std::ostream& operator<<(std::ostream& out, const MenuItem& sum);
            friend bool operator>(const MenuItem& mi1, const MenuItem& mi2);
            friend bool operator==(const MenuItem& mi1, const MenuItem& mi2);
            friend bool operator<(const MenuItem& mi1, const MenuItem& mi2);

        private:
            AbstractItem* item = nullptr;
    };
    std::ostream& operator<<(std::ostream& out, const MenuItem& sum);
    bool operator>(const MenuItem& mi1, const MenuItem& mi2);
    bool operator==(const MenuItem& mi1, const MenuItem& mi2);
    bool operator<(const MenuItem& mi1, const MenuItem& mi2);
}
