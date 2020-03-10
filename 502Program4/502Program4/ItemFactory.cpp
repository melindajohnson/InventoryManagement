#include "ItemFactory.h"


int ItemFactory::hash(char ch) const{
   return ch-'A';
   
}

ItemFactory::ItemFactory() {
 for (int i = 0; i < numberOfItems; i++) {
      if(i==2) itemFactory[2] = new ComicBook;
      else if(i==12) itemFactory[12] = new Coin;
      else if(i==18) itemFactory[18] = new SportsCard;
      else itemFactory[i] = NULL;
 }
}

 ItemFactory:: ~ItemFactory() {
   for (int i = 0; i < numberOfItems; i++) {
      delete itemFactory[i];
      itemFactory[i] = NULL;
   }
   
}

Item* ItemFactory::make_Item(char ch) const {
   int subscript = hash(ch);             // would do error checking
   if(itemFactory[subscript] != nullptr){
   return itemFactory[subscript]->create();
   } else return nullptr;
}
