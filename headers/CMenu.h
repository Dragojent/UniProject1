#pragma once

#include <iostream>
#include <cstdio>
#include "myArray.h"
#include "AbstractItem.h"
#include "MenuItem.h"
        
namespace FAS
{
    class CMenu 
    {
        public:
            CMenu(const char* title, myArray<MenuItem> items);
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
            myArray<MenuItem> GetItems();

            void runCommand();
            virtual void print();
            virtual void Start();

        protected:
            int m_select = -1;
            bool m_running = false;
            char* m_title = nullptr;

        private:
            myArray<MenuItem> m_item;
    };
}