/*
 BuyCommand.h
 Created by Melinda Stannah Stanley Jothiraj on 11/27/19.
 Student number- 1978413
 BuyCommand class: is a derived class from the Command class that has

 an overriden create method to create dummy BuyCommand objects
 an overriden execute method to execute the Buy Command which increase the inventoryCount of an item
 ---------------------------------------------------------------------------
 */

#pragma once
#include <stdio.h>
#include "Command.h"
class BuyCommand: public Command{

public:
   /**
    //-------------------------- Default constructor  for class BuyCommand  ------------------------------------//
    Create a new BuyCommand Object
    */
   BuyCommand();
   /**
    //-------------------------- Destructor for class BuyCommand  ------------------------------------//
    Destroys object and frees memory allocated by object.
    */
   virtual ~BuyCommand();
   /**
    //-------------------------- Create method  for class BuyCommand  ------------------------------------//
    Create a new dummy  BuyCommand Object
    @return new Command Object
    */
   virtual Command* create() const override;
   
   /**
    //-------------------------- Execute method  for class BuyCommand  ------------------------------------//
    execute the Buy Command which increase the inventoryCount of an item
    */
   virtual void execute(std::string commandString, StoreRepository *store) override;
};
