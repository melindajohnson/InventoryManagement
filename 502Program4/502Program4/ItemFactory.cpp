

#include "ItemFactory.h"

Item* ItemFactory::make_Item(std::string itemCode){
   if (itemCode == "M")
      return new Coin;
   else if (itemCode == "C")
      return new ComicBook;
   else if (itemCode == "S")
      return new SportsCard;
   else return new Item;
}
