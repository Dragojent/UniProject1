#include <iostream>
#include "stdlib.h"
#include "CMenu.h"
#include "User.h"

FAS::CMenu currentMenu{};

void test()
{
    std::cout << 1 << std::endl;
}

void test2()
{
    std::cout << 2 << std::endl;
}

void ExecMenu()
{
    currentMenu.Start();
}

int main()
{
    FAS::User newUser("name", FAS::User::AccessLevel::user);

    FAS::MenuItem _list[10]{
        {"Onegf", test},
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

    FAS::CMenu _menu("Menu", _list, 10);
    currentMenu = _menu;

    FAS::MenuItem list[10]{
        {"One", ExecMenu},
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