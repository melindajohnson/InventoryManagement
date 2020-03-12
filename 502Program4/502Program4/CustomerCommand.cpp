
#include "CustomerCommand.h"

/**
 //-------------------------- Default constructor  for class CustomerCommand  ------------------------------------//
 Create a new CustomerCommand Object
 */
CustomerCommand::CustomerCommand(){
   
}

/**
 //-------------------------- Parametric constructor  for class CustomerCommand  ------------------------------------//
 Create a new Command Object
 */
Command* CustomerCommand::create() const {
   return new CustomerCommand;
}
void CustomerCommand::execute(std::string commandString, StoreRepository *store) {
   readInput(commandString);
   Customer *c1 = dynamic_cast<Customer*>(store->customerHash->getValue(customerId));
   if(c1!= nullptr){
      std::cout << *c1 ;
   } else{
      std::cout <<" Customer does not exist"<< std::endl;
   }
}
