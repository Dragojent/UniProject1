#ifndef DBPOITER_H
#define DBPOITER_H

#include <iostream>
#include <fstream>
#include "AbstractItem.h"

namespace FAS
{
    // class AbstractItem;
    class DBPointer
    {
    public:
        DBPointer();
        DBPointer(size_t id);
        DBPointer(AbstractItem& item);
        DBPointer(DBPointer& ptr);
        ~DBPointer();

        std::streampos pos() const;
        std::streamsize size() const;

        AbstractItem read() const;
        void write(AbstractItem& item);

        DBPointer& operator=(const DBPointer& ptr);

    private:
        std::streampos m_pos;
        std::streamsize m_size;
    };
}

#endif