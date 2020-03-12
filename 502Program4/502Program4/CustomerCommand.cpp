
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
