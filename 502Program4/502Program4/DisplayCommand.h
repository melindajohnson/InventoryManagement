/*
 DisplayCommand.h
 Created by Melinda Stannah Stanley Jothiraj on 11/27/19.
 Student number- 1978413
 DisplayCommand class: is a derived class from the Command class that has
 
 an overriden create method to create dummy DisplayCommand objects
 an overriden execute method to execute the DisplayCommand which outputs the entire inventory of the store, including the number of each item in inventory
 ---------------------------------------------------------------------------
 */
#pragma once
#include <stdio.h>
#include "Command.h"

class DisplayCommand: public Command{
 
public:
   
   /**
    //-------------------------- Default constructor  for class DisplayCommand  ------------------------------------//
    Create a new DisplayCommand Object
    */
   DisplayCommand();
   /**
    //-------------------------- Destructor for class DisplayCommand  ------------------------------------//
    Destroys object and frees memory allocated by object.
    */
   virtual ~DisplayCommand();
   /**
    //-------------------------- Create method  for class DisplayCommand  ------------------------------------//
    Create a new dummy  DisplayCommand Object
    @return new Command Object
    */
   virtual Command* create() const override;
   /**
    //-------------------------- Execute method for class DisplayCommand  ------------------------------------//
    Outputs the entire inventory of the store, including the number of each item in inventory
    */
   virtual void execute(std::string commandString, StoreRepository *store) override;
};
