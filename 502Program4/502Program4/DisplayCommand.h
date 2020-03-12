
#pragma once
#include <stdio.h>
#include "Command.h"

class DisplayCommand: public Command{
   
private:
   
public:
   
   /**
    //-------------------------- Default constructor  for class DisplayCommand  ------------------------------------//
    Create a new DisplayCommand Object
    */
   DisplayCommand();
   
   /**
    //-------------------------- Parametric constructor  for class Command  ------------------------------------//
    Create a new Command Object
    */
   virtual Command* create() const override;
   
   virtual void execute(std::string customerId, std::string itemCode, std::string description) override;
};
