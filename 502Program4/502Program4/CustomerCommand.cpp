/*
 CustomerCommand.cpp
 Created by Melinda Stannah Stanley Jothiraj on 11/27/19.
 Student number- 1978413
 CustomerCommand class: is a derived class from the Command class that has
 
 an overriden create method to create dummy CustomerCommand objects
 an overriden execute method to execute the CustomerCommand which outputs all of the transactions for a customer (in chronological order), including the item
 ---------------------------------------------------------------------------
 */
#include "CustomerCommand.h"

/**
 //-------------------------- Default constructor  for class CustomerCommand  ------------------------------------//
 Create a new CustomerCommand Object
 */
CustomerCommand::CustomerCommand(){
   
}
/**
 //-------------------------- Destructor for class CustomerCommand  ------------------------------------//
 Destroys object and frees memory allocated by object.
 */
CustomerCommand:: ~CustomerCommand(){
   
}

/**
 //-------------------------- Create method  for class CustomerCommand  ------------------------------------//
 Create a new dummy  CustomerCommand Object
 @return new Command Object
 */
Command* CustomerCommand::create() const {
   return new CustomerCommand;
}

/**
 //-------------------------- Execute method for class CustomerCommand  ------------------------------------//
 Outputs all of the transactions for a customer (in chronological order), including the item
 */
void CustomerCommand::execute(std::string commandString, StoreRepository *store) {
   readInput(commandString);
   //based on the input from the command file get the customer and print out the customers transactions
   CustomerRepository *c1 = dynamic_cast<CustomerRepository*>(store->customerHash->getValue(customerId));
   if(c1!= nullptr){
      std::cout << *c1 ;
   } else{
      std::cout <<" Customer does not exist"<< std::endl;
   }
}
