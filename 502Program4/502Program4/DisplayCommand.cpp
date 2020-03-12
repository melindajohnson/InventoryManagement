
#include "DisplayCommand.h"

/**
 //-------------------------- Default constructor  for class DisplayCommand  ------------------------------------//
 Create a new DisplayCommand Object
 */
DisplayCommand::DisplayCommand(){
   
}

/**
 //-------------------------- Parametric constructor  for class DisplayCommand  ------------------------------------//
 Create a new Command Object
 */
Command* DisplayCommand::create() const {
   return new DisplayCommand;
}
void DisplayCommand::execute(std::string commandString, Store *store) {
   std::cout << std::endl;
   std::vector<HashValueType*> itemsContent = store->treeHash->getContents();
   for (auto it = begin (itemsContent); it != end (itemsContent); ++it) {
      BinarySearchTree *item = dynamic_cast<BinarySearchTree*>(*it);
      if(item != nullptr){
         std::cout << *item;
      }
   }
}
