#pragma once
#include "AbstractItem.h"
#include "myArray.h"
#include "User.h"

namespace FAS
{
    class Photo : public AbstractItem
    {
        public:
            Photo(const char* name, const char* _content);
            Photo(const char* name, const char* _content, myArray<User> _people);
            Photo(Photo& copy);
            Photo();
            ~Photo();

            unsigned int GetSize() const;
            void View();
            myArray<User> GetItems();
            void SetPeople();
            void AddPeople();
            void Edit();
            void Sort();
            void erase(unsigned int index);
            int add(User user);
            myArray<User*> filter(const char* ex);

            User& operator[](const unsigned int index);
            Photo& operator=(const Photo& photo);
        private:
            myArray<User> people;
            char* content;
    };
}