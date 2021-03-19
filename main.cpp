#include <iostream>
#include "stdlib.h"
#include "CMenu.h"
#include "User.h"
#include "myArray.h"

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
    FAS::MenuItem tmp("item", test), tmp1("item2", test2), tmp2("item3", test);

    FAS::myArray<FAS::MenuItem> arr;
    arr.push(tmp);
    arr.push(tmp1);
    arr.pop().PrintName();

    system("pause");
    // FAS::User newUser("name", FAS::User::AccessLevel::user);

    // FAS::MenuItem _list[10]{
    //     {"Onegf", test},
    //     {"Two", test2},
    //     {"One", test},
    //     {"One", test},
    //     {"One", test},
    //     {"One", test},
    //     {"Two", test2},
    //     {"Two", test2},
    //     {"Two", test2},
    //     {"Two", test2}
    // };

    // FAS::CMenu _menu("Menu", _list, 10);
    // currentMenu = _menu;

    // FAS::MenuItem list[10]{
    //     {"One", ExecMenu},
    //     {"Two", test2},
    //     {"One", test},
    //     {"One", test},
    //     {"One", test},
    //     {"One", test},
    //     {"Two", test2},
    //     {"Two", test2},
    //     {"Two", test2},
    //     {"Two", test2}
    // };

    // FAS::CMenu menu("Menu", list, 10);

    // menu.Start();

    return 0;
}