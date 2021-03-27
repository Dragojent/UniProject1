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
    FAS::myArray<char*> people{
        {"Tim"},
        {"Kate"}
    };

    system("pause");

    // FAS::Photo photo("lfd", "ff", people);

    for (int i = 0; i < 3000; i++)
    {
        FAS::myArray<FAS::Photo> photos{
            {"vacation", "__~~~__", people},
            {"vacation1", "__~+~__", people},
            {"vacation2", "__~-~__", people}
        };
        // if (i % 100 == 0)
        //     system("pause");
    }


    system("pause");
    // photos.print();


    return 0;
}