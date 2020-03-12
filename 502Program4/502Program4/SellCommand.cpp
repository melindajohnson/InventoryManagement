
#include "SellCommand.h"
/**
 //-------------------------- Default constructor  for class SellCommand  ------------------------------------//
 Create a new SellCommand Object
 */
SellCommand::SellCommand(){
   
}
/**
 //-------------------------- Parametric constructor  for class SellCommand  ------------------------------------//
 Create a new Command Object
 */
Command* SellCommand::create() const {
   return new SellCommand;
}

void SellCommand::execute(std::string commandString, Store *store){
   readInput(commandString);
   Customer *c1 = dynamic_cast<Customer*>(store->customerHash->getValue(customerId));
   if(c1!= nullptr){
      BinarySearchTree *itemTree = dynamic_cast<BinarySearchTree*>(store->treeHash->getValue(itemCode));
      Item *ptr = store->itemFactory.buildItemsByFactory(itemCode);
      if(ptr!= nullptr && itemTree!= nullptr){
         ptr->setData(" ", description);
         Item *item = dynamic_cast<Item*>(itemTree->retrieve(*ptr));
            //increase inventory of the particular object by 1
         item->decreaseInventory();
         TransactionItem *t1 = new TransactionItem("Sell", item);
         c1->addTransactions(t1);
      }
      else {
         std::cout <<"Item does not exist in inventory"<< std::endl;
      }
   }
   else { std::cout <<"Customer does not exist"<< std::endl;
   }
}
