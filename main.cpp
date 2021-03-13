#include <iostream>
#include "stdlib.h"
#include "CMenu.h"

int test()
{
    return 1;
}

int test2()
{
    return 2;
}

void PrintMenu(FAS::CMenu* menu)
{
    for (int i = 0; i < menu->GetNumberOfItems(); i++)
    {
        if (i == menu->GetSelect())
        {
            std::cout << ">";
        }
        std::cout << menu->GetItems()[i].GetName() << std::endl;
    }
}

int main()
{
    typedef char key;
    FAS::MenuItem list[10]{
        {"One", test},
        {"Two", test2},
        {"One", test},
        {"One", test},
        {"One", test},
        {"One", test},
        {"Two", test2},
        {"Two", test2},
        {"Two", test2},
        {"Two", test2}
    };

    FAS::CMenu menu("Menu", list, 10);

    menu.Start();

    return 0;
}