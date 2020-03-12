
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
void HistoryCommand::execute(std::string commandString, StoreRepository *store) {
   std::cout << store->customerTree;
}
