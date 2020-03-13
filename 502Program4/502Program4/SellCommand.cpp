/*
 SellCommand.cpp
 Created by Melinda Stannah Stanley Jothiraj on 11/27/19.
 Student number- 1978413
 BuyCommand class: is a derived class from the Command class that has
 
 an overriden create method to create dummy SellCommand objects
 an overriden execute method to execute the SellCommand which decreases the inventoryCount of an item
 ---------------------------------------------------------------------------
 */
#include "SellCommand.h"
/**
 //-------------------------- Default constructor  for class SellCommand  ------------------------------------//
 Create a new SellCommand Object
 */
SellCommand::SellCommand(){
   
}
/**
   //-------------------------- Destructor for class SellCommand  ------------------------------------//
Destroys object and frees memory allocated by object.
*/
SellCommand:: ~SellCommand(){
   
}
/**
 //-------------------------- Create method  for class SellCommand  ------------------------------------//
 Create a new dummy  SellCommand Object
 @return new Command Object
 */
Command* SellCommand::create() const {
   return new SellCommand;
}

/**
 //-------------------------- Execute method  for class SellCommand  ------------------------------------//
 execute the Sell Command which decrease the inventoryCount of an item
 */
void SellCommand::execute(std::string commandString, StoreRepository *store){
   readInput(commandString);
   //based on the input from the command file get the customer, itemTree, and then the item whose inventory has to be decreased if they all exist
   CustomerRepository *c1 = dynamic_cast<CustomerRepository*>(store->customerHash->getValue(customerId));
   if(c1!= nullptr){
      Item *ptr = store->itemFactory.make_Item(itemCode);
      if(ptr!= nullptr){
         ptr->setData(" ", description);
         Item *item = dynamic_cast<Item*>(store->itemtree.retrieve(*ptr));
            //increase inventory of the particular object by 1 if inventory count of the item is greater than 0
         if(item!=nullptr){
            if(item->decreaseInventory()){
         TransactionEntry *t1 = new TransactionEntry("Sell", item);
         c1->addTransactions(t1);
            }
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
