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
                administrator = 2
            };
            
            User(std::string name, AccessLevel AL);
            User(User& copy);
            User();
            ~User();

            AccessLevel accessLevel() const;
            void SetAccessLevel(AccessLevel AL); 

        private:
            AccessLevel m_accessLevel;
    };
}