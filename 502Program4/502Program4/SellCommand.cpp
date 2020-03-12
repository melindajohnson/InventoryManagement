
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
