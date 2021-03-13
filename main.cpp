#include <iostream>
#include "stdlib.h"
#include "CMenu.h"
#include "User.h"

int test()
{
    return 1;
}

int test2()
{
    return 2;
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