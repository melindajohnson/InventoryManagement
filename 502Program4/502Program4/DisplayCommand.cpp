/*
 DisplayCommand.cpp
 Created by Melinda Stannah Stanley Jothiraj on 11/27/19.
 Student number- 1978413
 DisplayCommand class: is a derived class from the Command class that has
 
 an overriden create method to create dummy DisplayCommand objects
 an overriden execute method to execute the DisplayCommand which outputs the entire inventory of the store, including the number of each item in inventory
 ---------------------------------------------------------------------------
 */
#include "DisplayCommand.h"

/**
 //-------------------------- Default constructor  for class DisplayCommand  ------------------------------------//
 Create a new DisplayCommand Object
 */
DisplayCommand::DisplayCommand(){
   
}

/**
 //-------------------------- Destructor for class DisplayCommand  ------------------------------------//
 Destroys object and frees memory allocated by object.
 */
DisplayCommand:: ~DisplayCommand(){
   
}
/**
 //-------------------------- Create method  for class DisplayCommand  ------------------------------------//
 Create a new dummy  DisplayCommand Object
 @return new Command Object
 */
Command* DisplayCommand::create() const {
   return new DisplayCommand;
}
/**
 //-------------------------- Execute method for class DisplayCommand  ------------------------------------//
 Outputs the entire inventory of the store, including the number of each item in inventory
 */
void DisplayCommand::execute(std::string commandString, StoreRepository *store) {
   std::cout << std::endl;
   std::cout << "Displaying all Inventory Items" << std::endl;
   std::cout << "------------------------------" << std::endl;
   std::cout << store->itemtree;
   std::cout <<  std::endl;
}
