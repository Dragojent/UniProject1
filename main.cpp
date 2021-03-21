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
    // FAS::User newUser("name", FAS::User::AccessLevel::user);

    FAS::myArray<FAS::MenuItem> list{
        {"one", test},
        {"two", test2},
        {"three", test}
    };

    list.print();

    FAS::CMenu menu("Menu", list, 2);

    menu.Start();

    return 0;
}