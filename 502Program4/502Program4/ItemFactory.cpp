#include "ItemFactory.h"

/**
 //-------------------------- Default constructor for class ItemFactory  ------------------------------------//
 Create a new ItemFactory Object
 */
ItemFactory::ItemFactory() {
    itemsHash->insert("C", new ComicBook);
    itemsHash->insert("M", new Coin);
    itemsHash->insert("S", new SportsCard);
}

/**
 //-------------------------- Destructor for class ItemFactory  ------------------------------------//
 Destroys object and frees memory allocated by object.
 */
 ItemFactory:: ~ItemFactory() {
       itemsHash->clear();
}
/**
 //-------------------------- make_Item method for class ItemFactory  ------------------------------------//
 Make a dummy item object based on the code from the inevtory file
 */
Item* ItemFactory::make_Item(std::string code) const {
   if(itemsHash->containsKey(code)){
      Item* ptr = dynamic_cast<Item*>(itemsHash->getValue(code));
      return ptr->create();
   }
   else return nullptr;
}
