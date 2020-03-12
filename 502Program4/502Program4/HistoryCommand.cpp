
#include "HistoryCommand.h"

/**
 //-------------------------- Default constructor  for class HistoryCommand  ------------------------------------//
 Create a new HistoryCommand Object
 */
HistoryCommand::HistoryCommand(){
   
}

/**
 //-------------------------- Parametric constructor  for class HistoryCommand  ------------------------------------//
 Create a new Command Object
 */
Command* HistoryCommand::create() const {
   return new HistoryCommand;
}
