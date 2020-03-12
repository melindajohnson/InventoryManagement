
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
   CustomerRepository *c1 = dynamic_cast<CustomerRepository*>(store->customerHash->getValue(customerId));
   if(c1!= nullptr){
      std::cout << *c1 ;
   } else{
      std::cout <<" Customer does not exist"<< std::endl;
   }
}
