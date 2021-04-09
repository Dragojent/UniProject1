#pragma once
#include <iostream>
#include "AbstractItem.h"

namespace FAS
{
    class User : public AbstractItem
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

            unsigned int GetSize() const;
            AccessLevel GetAccessLevel();
            void SetAccessLevel(AccessLevel setTo);

        private:
            AccessLevel accessLevel;
    };
}