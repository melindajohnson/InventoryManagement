
#pragma once
#include <stdio.h>
#include <string>
#include "Item.h"
#include "Coin.h"
#include "ComicBook.h"
#include "SportsCard.h"
const static unsigned int numberOfItems = 26;

class ItemFactory
{
private:
   Item* itemFactory[numberOfItems];
   int hash(char ch) const;

public:
   ItemFactory();
   virtual ~ItemFactory();
   Item* make_Item(char ch) const;
};
