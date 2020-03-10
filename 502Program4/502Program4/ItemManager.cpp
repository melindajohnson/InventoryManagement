
#include "ItemManager.h"

ItemManager::ItemManager(){
   
}

void ItemManager::buildItemsByFactory(std::ifstream &inventoryFile) {
   char code;                     // for reading from pretend data file
   Item* ptr;                     // the object obtained from factory
   
   
   for(;;){
      if (inventoryFile.eof()) break;
      std::string type;
      std::string stringCount;
      std::string description;
      getline(inventoryFile, type, ',');          //get type of inventory
      inventoryFile.get();          //discard space
      getline(inventoryFile, stringCount, ',');    //get count
                                                   //int intCount = atoi(stringCount.c_str());
      inventoryFile.get();          //discard space
      getline(inventoryFile, description, '\n');    //get rest of info
      
      code = type.at(0);
      ptr = objFactory.make_Item(code);
     // ptr->setData(stringCount, description);
     // myList.append(p);
   }
}

void ItemManager::displayItems() {
   //print all trees
   //cout << endl;
}

void ItemManager::destroyItems() {
//   myList.makeEmpty();
}

