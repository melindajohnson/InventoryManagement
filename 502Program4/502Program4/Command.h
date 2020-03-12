

#pragma once
#include <stdio.h>
#include <string>
#include "StoreRepository.h"
#include "CustomerRepository.h"
#include "TransactionEntry.h"

class Command: public HashValueType {
protected:
   std::string tokens[6];
   std::string customerId;          //customer Id
   std::string itemCode;    //item code
   std::string description; //command codepublic:
public:
   /**
    //-------------------------- Default constructor  for class Command  ------------------------------------//
    Create a new Command Object
    */
   Command();
   /**
    //-------------------------- Parametric constructor  for class Command  ------------------------------------//
    Create and new Command Object with the description provided
    */
   virtual Command* create() const = 0;
   
   virtual void execute(std::string commandString, StoreRepository *store) =0;
   
   virtual void readInput(std::string commandString);
};
