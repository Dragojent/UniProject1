#pragma once

namespace FAS
{
    class User 
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

            char* GetName();
            AccessLevel GetAccessLevel();
            void SetName(const char* setTo);
            void SetAccessLevel(AccessLevel setTo);

        private:

            char* name{}; 
            AccessLevel accessLevel = AccessLevel::user;
    };
}