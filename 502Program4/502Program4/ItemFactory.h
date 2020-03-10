
#pragma once
#include <stdio.h>
#include <string>
#include "Item.h"
#include "Coin.h"
#include "ComicBook.h"
#include "SportsCard.h"

class ItemFactory
{
private:
   Item* itemFactory[25]; // in general, do not hard code numbers, room to grow
   int hash(char ch) const;

public:
   ItemFactory();
   virtual ~ItemFactory();
   Item* make_Item(char ch) const;
};
