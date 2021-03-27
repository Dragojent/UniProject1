#pragma once

#include <iostream>
#include <cstdio>
#include "myArray.h"
#include "MenuItem.h"
        
namespace FAS
{
    class CMenu 
    {
        public:
            CMenu(const char* title, FAS::myArray<FAS::MenuItem> items, std::size_t count);
            CMenu(CMenu& copy);
            CMenu();
            ~CMenu();

            void SetRunning(bool setTo);
            void SetSelect(int setTo);
            void MoveSelect(int shift);

            int GetSelect();
            bool IsRunning();
            char* GetTitle();
            size_t GetNumberOfItems();
            FAS::myArray<FAS::MenuItem> GetItems();

            void print();
            void runCommand();
            void Start();

        private:
            int m_select = -1;
            bool m_running = false;
            char* m_title = nullptr;
            size_t m_count = 0;
            FAS::myArray<FAS::MenuItem> m_item;
    };
}