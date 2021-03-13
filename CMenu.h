#pragma once

#include <cstdio>
#include "MenuItem.h"
        
namespace FAS
{
    class CMenu {
        public:
            CMenu(const char* title, FAS::MenuItem* items, std::size_t count);
            CMenu(CMenu& copy);
            ~CMenu();

            void SetRunning(bool setTo);
            void SetSelect(int setTo);
            void MoveSelect(int shift);

            int GetSelect();
            bool IsRunning();
            char* GetTitle();
            size_t GetNumberOfItems();
            FAS::MenuItem* GetItems();

            void print();
            void runCommand();
            void Start();

        private:
            int m_select = -1;
            bool m_running = false;
            char* m_title = nullptr;
            size_t m_count = 0;
            FAS::MenuItem *m_item = nullptr;
    };
}