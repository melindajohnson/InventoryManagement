

#pragma once
#include <stdio.h>
#include "Comparable.h"
#include "HashValueType.h"

class Command: public HashValueType {
protected:
   Comparable* comparablePtr;
  // std::string code;  //code would S for sell and B for Buy
  // Item* itemPtr;
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
   
   virtual void execute(std::string customerId, std::string itemCode, std::string description) =0;
};
