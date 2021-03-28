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

            User& operator[](const unsigned int index);
            Photo& operator=(const Photo& photo);
        private:
            myArray<User> people;
            char* content;
    };
}