
#pragma once
#include <stdio.h>
#include "Command.h"

class HistoryCommand: public Command{
   
private:
   
public:
   /**
    //-------------------------- Default constructor  for class HistoryCommand  ------------------------------------//
    Create a new HistoryCommand Object
    */
   HistoryCommand();
   
   /**
    //-------------------------- Parametric constructor  for class Command  ------------------------------------//
    Create a new Command Object
    */
   virtual Command* create() const override;
   
   virtual void execute(std::string commandString, StoreRepository *store) override;
};
