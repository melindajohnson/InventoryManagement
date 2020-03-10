
#include "ItemManager.h"

ItemManager::ItemManager(){
   
}

void ItemManager::buildItemsByFactory(std::ifstream &inventoryFile, Hashtable &treeHash) {
   char code;                     // for reading from pretend data file
   Item* ptr;                     // the object obtained from factory
   while(inventoryFile.peek() != EOF){
      //if (inventoryFile.eof()) break;
      std::string type;
      std::string stringCount;
      std::string description;
      getline(inventoryFile, type, ',');          //get type of inventory
      inventoryFile.get();          //discard space
      getline(inventoryFile, stringCount, ',');    //get count
      inventoryFile.get();          //discard space
      getline(inventoryFile, description, '\n');    //get rest of info
      
      code = type.at(0);
      ptr = objFactory.make_Item(code);
      if(ptr!= nullptr){
         ptr->setData(stringCount, description);
         int key = code - 'A';
         if(treeHash.containsKey(key)){
            BinarySearchTree *tree = dynamic_cast<BinarySearchTree*>(treeHash.getValue(key));
            tree->insert(ptr);
         }else{
            BinarySearchTree *tree = new BinarySearchTree;
            treeHash.insert(key, tree);
            tree->insert(ptr);
         }
      }
   }
}

void ItemManager::displayItems() {
      //print all trees
      //cout << endl;
}

void ItemManager::destroyItems() {
      //   myList.makeEmpty();
}

