/*
 HistoryCommand.cpp
 Created by Melinda Stannah Stanley Jothiraj on 11/27/19.
 Student number- 1978413
 HistoryCommand class: is a derived class from the Command class that has
 
 an overriden create method to create dummy HistoryCommand objects
 an overriden execute method to execute the HistoryCommand which outputs the history for every customer, with the customers in alphabetical order.
 ---------------------------------------------------------------------------
 */
#include "HistoryCommand.h"

/**
 //-------------------------- Default constructor  for class HistoryCommand  ------------------------------------//
 Create a new HistoryCommand Object
 */
HistoryCommand::HistoryCommand(){
   
}
/**
 //-------------------------- Destructor for class HistoryCommand  ------------------------------------//
 Destroys object and frees memory allocated by object.
 */
HistoryCommand:: ~HistoryCommand(){
   
}
/**
 //-------------------------- Create method  for class HistoryCommand  ------------------------------------//
 Create a new dummy  HistoryCommand Object
 @return new Command Object
 */
Command* HistoryCommand::create() const {
   return new HistoryCommand;
}
/**
 //-------------------------- Execute method for class HistoryCommand  ------------------------------------//
 Outputs the history for every customer, with the customers in alphabetical order.
 */
void HistoryCommand::execute(std::string commandString, StoreRepository *store) {
   std::cout << std::endl;
   std::cout << "Displaying all Customers and their transaction items" << std::endl;
   std::cout << "----------------------------------------------------" << std::endl;
   std::cout << store->customerTree;  //outputs the Customer Tree
    std::cout << std::endl;
}
