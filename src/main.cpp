#include <iostream>
#include "stdlib.h"
#include "CMenu.h"
#include "User.h"
#include "myArray.h"

#define debug(code) try { code; } catch(const char* msg) { std::cout << msg << std::endl; } 

void test()
{
    std::cout << 1 << std::endl;
}

void test2()
{
    std::cout << 2 << std::endl;
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


    debug(FAS::CMenu menu("Menu", list, 2))

    // menu.Start();

    system("pause");
    return 0;
}