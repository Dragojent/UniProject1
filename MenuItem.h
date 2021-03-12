#pragma once

namespace FAS
{
    class MenuItem {
        public:
            typedef int(*Func)();

            MenuItem(const char* name, Func action);
            MenuItem(MenuItem& copy);
            ~MenuItem();

            char* GetName();
            void PrintName();
            int run();

        private:
            char* m_item_name = nullptr;
            Func m_func = nullptr;
    };
}