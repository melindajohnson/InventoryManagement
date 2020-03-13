
/*
 CommandFactory.h
 Created by Melinda Stannah Stanley Jothiraj on 11/27/19.
 Student number- 1978413
 CommandFactory class: is a Factory class that has a
 Hashatable commandHash
 a make_Command method to make a dummy command object based on the code from the command file
 a buildCommandsByFactory method to make a dummy command object
 ---------------------------------------------------------------------------
 */
#include "CommandFactory.h"

/**
 //-------------------------- Default constructor for class CommandFactory  ------------------------------------//
 Create a new CommandFactory Object
 */
CommandFactory::CommandFactory() {
   commandHash->insert("S", new SellCommand);
   commandHash->insert("B", new BuyCommand);
   commandHash->insert("H", new HistoryCommand);
   commandHash->insert("D", new DisplayCommand);
   commandHash->insert("C", new CustomerCommand);
}
/**
 //-------------------------- Destructor  for class CommandFactory  ------------------------------------//
 Destroys object and frees memory allocated by object.
 */
CommandFactory:: ~CommandFactory() {
   commandHash->clear();
}
/**
 //-------------------------- make_Command method for class CommandFactory  ------------------------------------//
 Make a dummy command object based on the code from the command file
 */
Command* CommandFactory::make_Command(std::string code) const {
   if(commandHash->containsKey(code)){
      Command* ptr = dynamic_cast<Command*>(commandHash->getValue(code));
      return ptr->create();
   }
   else return nullptr;
}
/**
 //-------------------------- buildCommandsByFactory method for class CommandFactory  ------------------------------------//
 Method to make a dummy command object
 */
Command* CommandFactory::buildCommandsByFactory(std::string code) const{
    return make_Command(code);
}
