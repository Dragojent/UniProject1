#ifndef PHOTO_H
#define PHOTO_H

#include "AbstractItem.h"
#include "User.h"
#include "myArray.h"

namespace FAS
{
    class Photo : public AbstractItem
    {
        public:
            Photo(std::string name, std::string content);
            Photo(std::string name, std::string content, myArray<User*> people);
            Photo(Photo& copy);
            Photo();
            ~Photo();

            void view() const;
            std::string content() const;
            void edit(std::string photo);

            void eraseUser(size_t index);
            size_t addUser(User* user);
            void setPeople(myArray<User*> people);
            myArray<User*> filter(std::string key) const;
            myArray<User*> people() const;
            void sort();

            User* operator[](const size_t index) const;
            Photo& operator=(const Photo& photo);
        private:
            myArray<User*> m_people;
            std::string m_content;
    };
}

#endif