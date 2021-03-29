#pragma once
#include <iostream>
#include "MenuItem.h"

namespace FAS
{
    class User : public MenuItem
    {
        public:
            enum class AccessLevel {
                user = 0,
                moderator = 1,
                admin = 2
            };
            
            User(const char* _name, AccessLevel aL);
            User(User& copy);
            User();
            ~User();

            AccessLevel GetAccessLevel();
            void SetAccessLevel(AccessLevel setTo);

        private:
            AccessLevel accessLevel;
    };
}