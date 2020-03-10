
#include "ItemManager.h"

ItemManager::ItemManager(){
   
}

void ItemManager::buildItemsByFactory(std::ifstream &inventoryFile, Hashtable &treeHash) {
 
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
      
      ptr = objFactory.make_Item(type);
         //if code is invalid skip over to the next line in file
      if(ptr!= nullptr){
         ptr->setData(stringCount, description);
        // int key = code - 'A';
         //create new tree for new code and then insert item else just insert item
         if(treeHash.containsKey(type)){
            BinarySearchTree *tree = dynamic_cast<BinarySearchTree*>(treeHash.getValue(type));
            tree->insert(ptr);
         }else{
            BinarySearchTree *tree = new BinarySearchTree;
            treeHash.insert(type, tree);
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

