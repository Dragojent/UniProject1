#pragma once

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

            char* GetName();
            void PrintName();
            void run();

        private:
            char* m_item_name = nullptr;
            Func m_func = nullptr;
    };
}