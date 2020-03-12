
#pragma once

#include <stdio.h>
#include "Command.h"
class BuyCommand: public Command{
private:
   
public:
   /**
    //-------------------------- Default constructor  for class BuyCommand  ------------------------------------//
    Create a new BuyCommand Object
    */
   BuyCommand();
   /**
    //-------------------------- Parametric constructor  for class Command  ------------------------------------//
    Create a new Command Object
    */
   virtual Command* create() const override;
   
   virtual void execute(std::string commandString, Store *store) override;
};
