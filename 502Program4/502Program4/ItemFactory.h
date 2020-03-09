
#pragma once
#include <stdio.h>
#include <string>
#include "Item.h"
#include "Coin.h"
#include "ComicBook.h"
#include "SportsCard.h"

class ItemFactory
{
public:
   // Factory Method
   static Item *make_Item(std::string itemCode);
   //virtual void create() = 0;
};
