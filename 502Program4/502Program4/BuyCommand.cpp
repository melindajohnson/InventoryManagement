/*
 BuyCommand.cpp
 Created by Melinda Stannah Stanley Jothiraj on 11/27/19.
 Student number- 1978413
 BuyCommand class: is a derived class from the Command class that has
 
 an overriden create method to create dummy BuyCommand objects
 an overriden execute method to execute the Buy Command which increase the inventoryCount of an item
 ---------------------------------------------------------------------------
 */
#include "BuyCommand.h"

/**
 //-------------------------- Default constructor  for class BuyCommand  ------------------------------------//
 Create a new BuyCommand Object
 */
BuyCommand::BuyCommand(){
   
}
/**
//-------------------------- Destructor for class BuyCommand  ------------------------------------//
Destroys object and frees memory allocated by object.
*/
BuyCommand:: ~BuyCommand(){
   
}
/**
 //-------------------------- Create method  for class BuyCommand  ------------------------------------//
 Create a new dummy  BuyCommand Object
 @return new Command Object
 */
Command* BuyCommand::create() const {
   return new BuyCommand;
}


/**
 //-------------------------- Execute method  for class BuyCommand  ------------------------------------//
 execute the Buy Command which increase the inventoryCount of an item
 */
void BuyCommand::execute(std::string commandString, StoreRepository *store) {
   readInput(commandString);
   //based on the input from the command file get the customer, itemTree, and then the item whose inventory has to be increased if they all exist
   CustomerRepository *c1 = dynamic_cast<CustomerRepository*>(store->customerHash->getValue(customerId));
   if(c1!= nullptr){
      Item *ptr = store->itemFactory.make_Item(itemCode);
      if(ptr!= nullptr){
         ptr->setData(" ", description);
         Item *item = dynamic_cast<Item*>(store->itemtree.retrieve(*ptr));
            //increase inventory of the particular object by 1
         if(item != nullptr){
         item->increaseInventory();
         TransactionEntry *t1 = new TransactionEntry("Buy", item);
         c1->addTransactions(t1);
      }else {
            std::cout <<"Item does not exist in inventory"<< std::endl;
         }
      }
      else {
         std::cout <<"Item does not exist in store"<< std::endl;
      }
   }
   else { std::cout <<"Customer does not exist"<< std::endl;
   }
}
