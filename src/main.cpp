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
        {"album1", photos},
        {"album2", photosNew}
    };

    FAS::Gallery gallery("gallery", albums);

    for (FAS::Album album : gallery.getAlbums())
        for(FAS::Photo photo : album.getPhotos())
            for(FAS::User user : photo.GetPeople())
            {
                gallery.GetName();
                album.PrintName();
                photo.PrintName();
                std::cout << user << "\n------------" << std::endl;
            }
    /*

    //Album.print prototype
    for (FAS::Photo photo : photos)
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

    */

    system("pause");

    return 0;
}