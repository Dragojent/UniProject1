#include "DBPointer.h"

#define DBLOC "Database\\storage.db"

FAS::DBPointer::DBPointer() :
    m_pos(-1)  {}

FAS::DBPointer::DBPointer(size_t id) :
    m_pos(-1)
{
    std::ifstream db{};
    std::streampos pos = m_pos;
    AbstractItem item{};
    db.open(DBLOC, std::ios::out | std::ios::binary);

    if(!db.is_open())
        throw "db access error";

    while(!db.eof())
    {
        db.read((char*)&item, sizeof(item));
        if (item.ID() == id)
        {
            m_pos = db.tellg();
            db.close();
            return;
        }
    }

    db.close();
    throw "item not found";
}

FAS::DBPointer::DBPointer(AbstractItem& item) :
    m_pos(0)
{
    write(item);
}

FAS::DBPointer::DBPointer(DBPointer& ptr) :
    m_pos(ptr.pos()) {}

std::streampos FAS::DBPointer::pos() const
{
    return m_pos;
}

FAS::DBPointer::~DBPointer() {}

FAS::AbstractItem FAS::DBPointer::read() const
{
    std::ifstream db;
    AbstractItem item;
    db.open (DBLOC, std::ios::binary);

    if(!db.is_open())
        throw "db access error";

    db.seekg(m_pos);
    db.read((char*)&item, sizeof(item));

    db.close();
    return item;
}

void FAS::DBPointer::write(AbstractItem& item)
{
    std::ofstream db;
    db.open (DBLOC, std::ios::binary | std::ios::app);

    if (!db.is_open())
        throw "db access error";

    db.seekp(0, std::ios::end);
    m_pos = db.tellp();

    db.write((char*)&item, sizeof(item));
    
    db.close();
}

FAS::DBPointer& FAS::DBPointer::operator=(const DBPointer& ptr)
{
    m_pos = ptr.pos();
    return *this;
}