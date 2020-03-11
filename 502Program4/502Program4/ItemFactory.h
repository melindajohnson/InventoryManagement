
#pragma once
#include <stdio.h>
#include <string>
#include "Item.h"
#include "Coin.h"
#include "ComicBook.h"
#include "SportsCard.h"
#include "Hashtable.h"
const static int numberOfItems = 26;

class ItemFactory
{
private:
   Hashtable *itemsHash = new Hashtable(numberOfItems);

public:
   ItemFactory();
   virtual ~ItemFactory();
   Item* make_Item(std::string code) const;
};
