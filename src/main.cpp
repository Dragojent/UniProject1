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
    FAS::myArray<FAS::User>
        people{
            {"Tim", FAS::User::AccessLevel::user},
            {"Kate", FAS::User::AccessLevel::user}
        },
        peopleNew{
            {"Roy", FAS::User::AccessLevel::user},
            {"Jake", FAS::User::AccessLevel::admin}
        };

    FAS::myArray<FAS::Photo> 
        photos{
            {"vacation", "__~~~__", people},
            {"vacation1", "__~+~__", people},
            {"vacation2", "__~-~__", people},
            {"vacation3", "__~*~__", people},
            {"School", "|__*__|", peopleNew},
            {"School1", "|__+__|", peopleNew},
            {"School2", "|__!__|", peopleNew},
        }, 
        photosNew{
            {"hotel", "|_~~~_|", people},
            {"hotel1", "|_~+~_|", people},
            {"hotel2", "|_~-~_|", people},
            {"hotel3", "|_~*~_|", people},
            {"SchoolNew", "~__*__~", peopleNew},
            {"SchoolNew1", "~__+__~", peopleNew},
            {"SchoolNew2", "~__!__~", peopleNew},
        };

    FAS::myArray<FAS::Album> albums{
        {"albgm4", photos},
        {"albus6", photos},
        {"album3", photos},
        {"dlbum5", photos},
        {"vlbum2", photos},
        {"album1", photosNew}
    };

    FAS::Gallery gallery("gallery", albums);

    std::cout << "Full gallery" << std::endl;
    for (auto al : gallery.GetItems())
    {
        al.PrintName();
        for (auto ph : al.GetItems())
        {
            std::cout << "-";
            ph.PrintName();
            for (auto us : ph.GetItems())
            {
                std::cout << "--";
                std::cout << us << std::endl;
            }
            std::cout << "----------" << std::endl;
        }
        std::cout << "=============" << std::endl;
    }

    system("pause");
    system("cls");

    gallery.sort();
    std::cout << "Sorted gallery" << std::endl;
    for (auto al : gallery.GetItems())
        al.PrintName();

    system("pause");
    system("cls");

    std::cout << "Filtered using 'alb' key gallery" << std::endl;
    for (auto* al : gallery.filter("alb"))
        al->PrintName();

    system("pause");
    system("cls");

    gallery.erase(0);
    gallery.erase(0);
    gallery.erase(0);
    std::cout << "Gallery after erasing first three albums" << std::endl;
    for (auto al : gallery.GetItems())
        al.PrintName();

    system("pause");
    system("cls");

    std::cout << "Write a name for a new album" << std::endl;
    std::cin >> gallery;

    std::cout << "Gallery with a new album" << std::endl;
    for (auto al : gallery.GetItems())
        al.PrintName();

    system("pause");

    return 0;
}