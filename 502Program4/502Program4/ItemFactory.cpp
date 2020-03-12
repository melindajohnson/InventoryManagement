#include "ItemFactory.h"


ItemFactory::ItemFactory() {
    itemsHash->insert("C", new ComicBook);
    itemsHash->insert("M", new Coin);
    itemsHash->insert("S", new SportsCard);
}

 ItemFactory:: ~ItemFactory() {
       itemsHash->clear();
}

Item* ItemFactory::make_Item(std::string code) const {
   if(itemsHash->containsKey(code)){
      Item* ptr = dynamic_cast<Item*>(itemsHash->getValue(code));
      return ptr->create();
   }
   else return nullptr;
}


Item* ItemFactory::buildItemsByFactory(std::string code) const{
   return make_Item(code);
}
