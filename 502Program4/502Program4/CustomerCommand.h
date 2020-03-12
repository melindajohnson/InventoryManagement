
#pragma once
#include <stdio.h>
#include "Command.h"

class CustomerCommand: public Command{
   
private:
   
public:
   
   /**
    //-------------------------- Default constructor  for class CustomerCommand  ------------------------------------//
    Create a new CustomerCommand Object
    */
   CustomerCommand();
   
   /**
    //-------------------------- Parametric constructor  for class Command  ------------------------------------//
    Create a new Command Object
    */
   virtual Command* create() const override;
   
    virtual void execute(std::string commandString, StoreRepository *store) override;
};
