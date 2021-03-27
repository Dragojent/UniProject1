#pragma once
#include "MenuItem.h"
#include "myArray.h"

namespace FAS
{
    class Photo : public MenuItem
    {
        public:
            Photo(const char* name, const char* _content);
            Photo(const char* name, const char* _content, myArray<char*> _people);
            Photo(Photo& copy);
            Photo();
            ~Photo();

            void Print();
            myArray<char*> GetPeople();
            void SetPeople();
            void AddPeople();
            void Edit();
        private:
            myArray<char*> people;
            char* content;
    };
}