#ifndef ABSITEM_H
#define ABSITEM_H

#include "myArray.h"
#include <iostream>
#include <ctime>

namespace FAS
{
    class AbstractItem 
    {
        public:
            AbstractItem(std::string name);
            AbstractItem(AbstractItem& copy);
            AbstractItem();
            virtual ~AbstractItem();

            void setName(std::string name);
            void printName() const;
            std::string name() const;
            size_t ID() const;

            friend std::ostream& operator<<(std::ostream& out, const AbstractItem& sum);
            friend bool operator>(const AbstractItem& mi1, const AbstractItem& mi2);
            friend bool operator==(const AbstractItem& mi1, const AbstractItem& mi2);
            friend bool operator<(const AbstractItem& mi1, const AbstractItem& mi2);
            friend std::istream& operator>>(std::istream& in, AbstractItem& sum);
 
        protected:
            std::string m_name;
            std::time_t m_ID;
    };
    std::ostream& operator<<(std::ostream& out, const AbstractItem& sum);
    bool operator>(const AbstractItem& mi1, const AbstractItem& mi2);
    bool operator==(const AbstractItem& mi1, const AbstractItem& mi2);
    bool operator<(const AbstractItem& mi1, const AbstractItem& mi2);
    std::istream& operator>>(std::istream& in, AbstractItem& sum);
}

#endif