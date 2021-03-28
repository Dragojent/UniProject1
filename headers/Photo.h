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

            Photo& operator=(const Photo& item);
        private:
            myArray<User> people;
            char* content;
    };
}