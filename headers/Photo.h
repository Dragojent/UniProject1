#pragma once
#include "MenuItem.h"
#include "myArray.h"
#include "User.h"

namespace FAS
{
    class Photo : public MenuItem
    {
        public:
            Photo(const char* name, const char* _content);
            Photo(const char* name, const char* _content, myArray<User> _people);
            Photo(Photo& copy);
            Photo();
            ~Photo();

            void View();
            myArray<User> GetPeople();
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