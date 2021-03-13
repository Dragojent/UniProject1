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