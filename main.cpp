#include <iostream>
#include "stdlib.h"
#include <conio.h> 
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
    key input{};

    menu.SetSelect(0);
    menu.SetRunning(true);
    while (menu.IsRunning())
    {
        system("cls");
        PrintMenu(&menu);
        input = getch();
        switch (input)
        {
        case 's':
            menu.MoveSelect(1);
            break;
        
        case 'w':
            menu.MoveSelect(-1);
            break;

        case 27:
            menu.SetRunning(false);
            break;

        case 32:
            system("cls");
            menu.runCommand();
            system("pause");
            break;

        default:
            break;
        }
    }

    return 0;
}