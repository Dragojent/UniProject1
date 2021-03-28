#include <iostream>
#include "stdlib.h"
#include "CMenu.h"
#include "User.h"
#include "myArray.h"
#include "Photo.h"
#include "Gallery.h"
#include "Album.h"

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
    FAS::myArray<FAS::User> people{
        {"Tim", FAS::User::AccessLevel::user},
        {"Kate", FAS::User::AccessLevel::user}
    };

    FAS::myArray<FAS::User> peopleNew{
        {"Roy", FAS::User::AccessLevel::user},
        {"Jake", FAS::User::AccessLevel::admin}
    };

    FAS::myArray<FAS::Photo> album{
        {"vacation", "__~~~__", people},
        {"vacation1", "__~+~__", people},
        {"vacation2", "__~-~__", people},
        {"vacation3", "__~*~__", people},
        {"School", "|__*__|", peopleNew},
        {"School1", "|__+__|", peopleNew},
        {"School2", "|__!__|", peopleNew},
    };

    //Album.print prototype
    for (FAS::Photo photo : album)
    {
        photo.PrintName();
        photo.View();
        //Photo.printUsers prototype
        for (FAS::User user : photo.GetPeople())
        {
            std::cout << user;
        }
        std::cout << "---------" << std::endl;
    }

    system("pause");

    return 0;
}