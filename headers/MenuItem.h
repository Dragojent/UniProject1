#pragma once
#include <iostream>
#include <ctime>

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

            void SetName(const char* name);
            char* GetName() const;
            void PrintName() const;
            std::time_t GetID();
            virtual void run();

            friend std::ostream& operator<<(std::ostream& out, const MenuItem& sum);
            MenuItem& operator=(const MenuItem &item);
            friend bool operator>(const MenuItem& mi1, const MenuItem& mi2);
            friend bool operator==(const MenuItem& mi1, const MenuItem& mi2);
            friend bool operator<(const MenuItem& mi1, const MenuItem& mi2);
 
        protected:
            char* m_item_name = nullptr;
            std::time_t ID;

        private:
            Func m_func = nullptr;
    };
    std::ostream& operator<<(std::ostream& out, const MenuItem& sum);
    bool operator>(const MenuItem& mi1, const MenuItem& mi2);
    bool operator==(const MenuItem& mi1, const MenuItem& mi2);
    bool operator<(const MenuItem& mi1, const MenuItem& mi2);
}