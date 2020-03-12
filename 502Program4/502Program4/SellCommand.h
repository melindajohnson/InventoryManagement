
#pragma once

#include <stdio.h>
#include "Command.h"
class SellCommand: public Command{
private:
   
public:
   /**
    //-------------------------- Default constructor  for class SellCommand  ------------------------------------//
    Create a new SellCommand Object
    */
   SellCommand();
   /**
    //-------------------------- Parametric constructor  for class Command  ------------------------------------//
    Create a new Command Object
    */
   virtual Command* create() const override;
   
   virtual void execute(std::string commandString, StoreRepository *store) override;
};
