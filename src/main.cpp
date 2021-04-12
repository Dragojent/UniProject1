#include <iostream>
#include "stdlib.h"
#include "CMenu.h"
#include "User.h"
#include "myArray.h"
#include "Photo.h"
#include "AbstractItem.h"
#include "Gallery.h"
#include "Album.h"

#define debug(code) try { code; } catch(const char* msg) { std::cout << msg << std::endl; } 

int main()
{
    FAS::User Tim{"Tim", FAS::User::AccessLevel::user},
              Kate{"Kate", FAS::User::AccessLevel::user},
              Roy{"Roy", FAS::User::AccessLevel::user},
              Jake{"Jake", FAS::User::AccessLevel::administrator};

    FAS::myArray<FAS::User*> people{&Tim, &Kate},
                             peopleNew{&Roy, &Jake};

    FAS::Photo photo1{"vacation", "__~~~__", people},
               photo2{"vacation1", "__~+~__", people},
               photo3{"vacation2", "__~-~__", people},
               photo4{"vacation3", "__~*~__", people},
               photo5{"School", "|__*__|", peopleNew},
               photo6{"School1", "|__+__|", peopleNew},
               photo7{"School2", "|__!__|", peopleNew},
               photo8{"hotel", "|_~~~_|", people},
               photo9{"hotel1", "|_~+~_|", people},
               photo10{"hotel2", "|_~-~_|", people},
               photo11{"hotel3", "|_~*~_|", people},
               photo12{"SchoolNew", "~__*__~", peopleNew},
               photo13{"SchoolNew1", "~__+__~", peopleNew},
               photo14{"SchoolNew2", "~__!__~", peopleNew};

    FAS::myArray<FAS::Photo*> 
        photos{
        &photo1, &photo2, &photo3, &photo4, &photo5, &photo5, &photo6, &photo7
    }, 
        photosNew{
        &photo8, &photo9, &photo10, &photo11, &photo12, &photo13, &photo14
    };

    FAS::Album Al1{"albgm4", photos},
               Al2{"albus6", photos},
               Al3{"album3", photos},
               Al4{"dlbum5", photosNew},
               Al5{"vlbum2", photosNew},
               Al6{"album1", photosNew};

    FAS::myArray<FAS::Album*> albums{
        &Al1, &Al2, &Al3, &Al4, &Al5, &Al6
    };

    FAS::Gallery gallery("gallery", albums);

    system("pause");

    return 0;
}