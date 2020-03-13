/*
 HistoryCommand.h
 Created by Melinda Stannah Stanley Jothiraj on 11/27/19.
 Student number- 1978413
 HistoryCommand class: is a derived class from the Command class that has
 
 an overriden create method to create dummy HistoryCommand objects
 an overriden execute method to execute the HistoryCommand which outputs the history for every customer, with the customers in alphabetical order.
 ---------------------------------------------------------------------------
 */
#pragma once
#include <stdio.h>
#include "Command.h"

class HistoryCommand: public Command{

public:
   /**
    //-------------------------- Default constructor  for class HistoryCommand  ------------------------------------//
    Create a new HistoryCommand Object
    */
   HistoryCommand();
   /**
    //-------------------------- Destructor for class HistoryCommand  ------------------------------------//
    Destroys object and frees memory allocated by object.
    */
   virtual ~HistoryCommand();
   /**
    //-------------------------- Create method  for class HistoryCommand  ------------------------------------//
    Create a new dummy  HistoryCommand Object
    @return new Command Object
    */
   virtual Command* create() const override;
   
   /**
    //-------------------------- Execute method for class HistoryCommand  ------------------------------------//
    Outputs the history for every customer, with the customers in alphabetical order.
    */
   virtual void execute(std::string commandString, StoreRepository *store) override;
};
