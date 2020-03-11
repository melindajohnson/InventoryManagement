
#include "ItemManager.h"

ItemManager::ItemManager(){
   
}

Item* ItemManager::buildItemsByFactory(std::string type) {
    // the object obtained from factory
   return objFactory.make_Item(type);
}

void ItemManager::displayItems() {
      //print all trees
      //cout << endl;
}

void ItemManager::destroyItems() {
      //   myList.makeEmpty();
}

