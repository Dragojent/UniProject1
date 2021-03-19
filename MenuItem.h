#pragma once
#include <iostream>

namespace FAS
{
    class MenuItem 
    {
        public:
            typedef void(*Func)();

            MenuItem(const char* name, Func action);
            MenuItem(MenuItem& copy);
            MenuItem();
            ~MenuItem();

            char* GetName() const;
            void PrintName() const;
            void run();

            friend std::ostream& operator<<(std::ostream& out, const MenuItem& sum)
            {
                sum.PrintName();
                return out;
            }
 
        private:
            char* m_item_name = nullptr;
            Func m_func = nullptr;
    };
}