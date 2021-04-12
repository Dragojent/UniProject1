#include "MenuItem.h"
#include "CMenu.h"
#include <cstring>

FAS::MenuItem::MenuItem(AbstractItem& _item)
{
    item = &_item;
}

FAS::MenuItem::MenuItem(MenuItem& copy)
{
    item = copy.item;
}

FAS::MenuItem::MenuItem()
{

}

FAS::MenuItem::~MenuItem()
{

}

// void FAS::MenuItem::run()
// {
//     myArray<MenuItem> arr{};
//     for (int i = 0; i < item->size(); i++)
//     {
//         MenuItem _item(item[i]);
//         arr.push_back(_item);
//     }
//     CMenu menu(item->name(), arr);
//     menu.Start();
// }

void FAS::MenuItem::PrintName()
{
    item->name();
}

FAS::MenuItem& FAS::MenuItem::operator=(const MenuItem& _item)
{
    item = _item.item;
    return *this;
}

FAS::AbstractItem& FAS::MenuItem::operator[](const unsigned int index)
{
    return item[index];
}

std::ostream& FAS::operator<<(std::ostream& out, const MenuItem& sum)
{
    sum.item->printName();
    return out;
}

bool FAS::operator>(const MenuItem& mi1, const MenuItem& mi2)
{
    return mi1.item->name() > mi2.item->name();
}

bool FAS::operator==(const MenuItem& mi1, const MenuItem& mi2)
{
    return mi1.item->name() == mi2.item->name();
}

bool FAS::operator<(const MenuItem& mi1, const MenuItem& mi2)
{
    return mi1.item->name() < mi2.item->name();
}