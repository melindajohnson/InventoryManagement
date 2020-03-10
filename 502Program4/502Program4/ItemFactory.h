
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
   const static unsigned int numberOfItems = 26;
   Item* itemFactory[numberOfItems];
   int hash(char ch) const;

public:
   ItemFactory();
   virtual ~ItemFactory();
   Item* make_Item(char ch) const;
};
