/*
 CustomerCommand.h
 Created by Melinda Stannah Stanley Jothiraj on 11/27/19.
 Student number- 1978413
 CustomerCommand class: is a derived class from the Command class that has
 
 an overriden create method to create dummy CustomerCommand objects
 an overriden execute method to execute the CustomerCommand which outputs all of the transactions for a customer (in chronological order), including the item
 ---------------------------------------------------------------------------
 */
#pragma once
#include <stdio.h>
#include "Command.h"

class CustomerCommand: public Command{

public:
   
   /**
    //-------------------------- Default constructor  for class CustomerCommand  ------------------------------------//
    Create a new CustomerCommand Object
    */
   CustomerCommand();
   /**
    //-------------------------- Destructor for class CustomerCommand  ------------------------------------//
    Destroys object and frees memory allocated by object.
    */
   virtual ~CustomerCommand();
   /**
    //-------------------------- Create method  for class CustomerCommand  ------------------------------------//
    Create a new dummy  CustomerCommand Object
    @return new Command Object
    */
   virtual Command* create() const override;
   
   /**
    //-------------------------- Execute method for class CustomerCommand  ------------------------------------//
    Outputs all of the transactions for a customer (in chronological order), including the item
    */
    virtual void execute(std::string commandString, StoreRepository *store) override;
};
