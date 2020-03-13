
/*
 Command.h
 Created by Melinda Stannah Stanley Jothiraj on 11/27/19.
 Student number- 1978413
 Command class: is a Abstract class that has
 some protected strings
 a create method to create dummy command objects
 a execute method to execute the right command
 a read input method that reads from the input command file
 ---------------------------------------------------------------------------
 */

#pragma once
#include <stdio.h>
#include <string>
#include "StoreRepository.h"
#include "CustomerRepository.h"
#include "TransactionEntry.h"

class Command: public HashValueType {
protected:
   std::string tokens[6];     //string to hold an input line from command file
   std::string customerId;    //customer Id
   std::string itemCode;      //item code
   std::string description;   //item description
public:
   /**
    //-------------------------- Default constructor for class Command  ------------------------------------//
    Create a new Command Object
    */
   Command();
   
   /**
    //-------------------------- Destructor for class Command  ------------------------------------//
     Destroys object and frees memory allocated by object.
    */
   virtual ~Command();
   
   /**
    //-------------------------- Create method  for class Command  ------------------------------------//
    Creates a new Command Object
    */
   virtual Command* create() const = 0;
   
   /**
    //-------------------------- Execute method  for class Command  ------------------------------------//
    executes a command based on the Command Object
    */
   virtual void execute(std::string commandString, StoreRepository *store) =0;
   /**
    //-------------------------- readInput method  for class Command  ------------------------------------//
    Reads from the input command file and sets the protected data memebers
    */
   virtual void readInput(std::string commandString);
};
