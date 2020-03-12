
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
