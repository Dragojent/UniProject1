#include <cstring>
#include "Photo.h"

FAS::Photo::Photo(std::string name, std::string content) :
    m_content({})
{
    m_name = name;
    m_content = content;
}

FAS::Photo::Photo(std::string name, std::string content, myArray<User*> people) :
    m_content({})
{
    m_name = name;
    m_content = content;
    m_people = people;
}

FAS::Photo::Photo(Photo& copy) :
    m_content({})
{
    m_name = copy.name();
    m_content = copy.content();
    m_people = copy.people();
}

FAS::Photo::Photo() : m_content({}) {}

FAS::Photo::~Photo() {}

void FAS::Photo::view() const
{
    std::cout << m_content << std::endl;
}

std::string FAS::Photo::content() const
{
    return m_content;
}

void FAS::Photo::edit(std::string photo)
{
    m_content = photo;
}

void FAS::Photo::eraseUser(size_t index)
{
    m_people.erase(index);
}

size_t FAS::Photo::addUser(User* user)
{
    return m_people.push_back(user);
}

void FAS::Photo::setPeople(myArray<User*> people)
{
    m_people = people;
}

FAS::myArray<FAS::User*> FAS::Photo::filter(std::string key) const
{
    myArray<User*> tmparr{};
    for (auto user : m_people)
        if (user->name() == key)
            tmparr.push_back(user);
    return tmparr;
}

FAS::myArray<FAS::User*> FAS::Photo::people() const
{
    return m_people;
}

void FAS::Photo::sort()
{
    for (int i = 0; i < m_people.size() - 1; i++)
        for (int j = 0; j < m_people.size() - i - 1; j++)
            if (m_people[j] > m_people[j + 1])
                m_people.swap(j, j + 1);
}

FAS::User* FAS::Photo::operator[](const size_t index) const
{
    return m_people[index];
}

FAS::Photo& FAS::Photo::operator=(const Photo& photo)
{   
    m_name = photo.name();
    m_ID =  photo.ID();
    m_people =  photo.people();
    return *this;
}
