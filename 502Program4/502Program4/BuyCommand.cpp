
#include "BuyCommand.h"

/**
 //-------------------------- Default constructor  for class BuyCommand  ------------------------------------//
 Create a new BuyCommand Object
 */
BuyCommand::BuyCommand(){
   
}

/**
 //-------------------------- Parametric constructor  for class BuyCommand  ------------------------------------//
 Create a new Command Object
 */
Command* BuyCommand::create() const {
   return new BuyCommand;
}

void BuyCommand::execute(std::string commandString, StoreRepository *store) {
   readInput(commandString);
   CustomerRepository *c1 = dynamic_cast<CustomerRepository*>(store->customerHash->getValue(customerId));
   if(c1!= nullptr){
      BinarySearchTree *itemTree = dynamic_cast<BinarySearchTree*>(store->treeHash->getValue(itemCode));
      Item *ptr = store->itemFactory.buildItemsByFactory(itemCode);
      if(ptr!= nullptr && itemTree!= nullptr){
         ptr->setData(" ", description);
         Item *item = dynamic_cast<Item*>(itemTree->retrieve(*ptr));
            //increase inventory of the particular object by 1
         item->increaseInventory();
         TransactionEntry *t1 = new TransactionEntry("buy", item);
         c1->addTransactions(t1);
      }
      else {
         std::cout <<"Item does not exist in inventory"<< std::endl;
      }
   }
   else { std::cout <<"Customer does not exist"<< std::endl;
   }
}
