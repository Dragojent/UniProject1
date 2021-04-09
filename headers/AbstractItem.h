#pragma once

#include "myArray.h"
#include <iostream>
#include <ctime>

namespace FAS
{
    class AbstractItem 
    {
        public:
            typedef void(*Func)();

            AbstractItem(const char* name);
            AbstractItem(AbstractItem& copy);
            AbstractItem();
            virtual ~AbstractItem();

            void SetName(const char* name);
            char* GetName() const;
            void PrintName() const;
            unsigned long GetID();
            virtual unsigned int GetSize() const;

            friend std::ostream& operator<<(std::ostream& out, const AbstractItem& sum);
            AbstractItem& operator=(const AbstractItem &item);
            friend bool operator>(const AbstractItem& mi1, const AbstractItem& mi2);
            friend bool operator==(const AbstractItem& mi1, const AbstractItem& mi2);
            friend bool operator<(const AbstractItem& mi1, const AbstractItem& mi2);
            friend std::istream& operator>>(std::istream& in, AbstractItem& sum);
 
        protected:
            char* m_item_name = nullptr;
            std::time_t ID;
    };
    std::ostream& operator<<(std::ostream& out, const AbstractItem& sum);
    bool operator>(const AbstractItem& mi1, const AbstractItem& mi2);
    bool operator==(const AbstractItem& mi1, const AbstractItem& mi2);
    bool operator<(const AbstractItem& mi1, const AbstractItem& mi2);
    std::istream& operator>>(std::istream& in, AbstractItem& sum);
}