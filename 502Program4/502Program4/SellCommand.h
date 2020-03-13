/*
 SellCommand.h
 Created by Melinda Stannah Stanley Jothiraj on 11/27/19.
 Student number- 1978413
 BuyCommand class: is a derived class from the Command class that has
 
 an overriden create method to create dummy SellCommand objects
 an overriden execute method to execute the SellCommand which decreases the inventoryCount of an item
 ---------------------------------------------------------------------------
 */
#pragma once
#include <stdio.h>
#include "Command.h"
class SellCommand: public Command{

public:
   /**
    //-------------------------- Default constructor  for class SellCommand  ------------------------------------//
    Create a new SellCommand Object
    */
   SellCommand();
   /**
    //-------------------------- Destructor for class SellCommand  ------------------------------------//
    Destroys object and frees memory allocated by object.
    */
   virtual ~SellCommand();
   /**
    //-------------------------- Create method  for class SellCommand  ------------------------------------//
    Create a new dummy  SellCommand Object
    @return new Command Object
      */
    virtual Command* create() const override;
  
   /**
    //-------------------------- Execute method  for class SellCommand  ------------------------------------//
    execute the Sell Command which decrease the inventoryCount of an item
    */
   virtual void execute(std::string commandString, StoreRepository *store) override;
};
