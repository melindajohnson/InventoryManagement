
#include "DisplayCommand.h"

/**
 //-------------------------- Default constructor  for class DisplayCommand  ------------------------------------//
 Create a new DisplayCommand Object
 */
DisplayCommand::DisplayCommand(){
   
}

/**
 //-------------------------- Parametric constructor  for class DisplayCommand  ------------------------------------//
 Create a new Command Object
 */
Command* DisplayCommand::create() const {
   return new DisplayCommand;
}
