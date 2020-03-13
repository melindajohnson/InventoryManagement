
/*
 CommandFactory.h
 Created by Melinda Stannah Stanley Jothiraj on 11/27/19.
 Student number- 1978413
 CommandFactory class: is a Factory class that has a
 Hashatable commandHash
 a make_Command method to make a dummy command object based on the code from the command file
 a buildCommandsByFactory method to make a dummy command object
 ---------------------------------------------------------------------------
 */

#include <stdio.h>
#include <string>
#include "Command.h"
#include "SellCommand.h"
#include "BuyCommand.h"
#include "HistoryCommand.h"
#include "DisplayCommand.h"
#include "CustomerCommand.h"
#include "Hashtable.h"
const static int numberOfCommand = 10;

class CommandFactory
{
private:
   // A hashtable of command codes as key and Dummy command objects as values
   Hashtable *commandHash = new Hashtable(numberOfCommand);
public:
   /**
    //-------------------------- Default constructor for class CommandFactory  ------------------------------------//
    Create a new CommandFactory Object
    */
   CommandFactory();
   /**
    //-------------------------- Destructor  for class CommandFactory  ------------------------------------//
    Destroys object and frees memory allocated by object.
    */
   virtual ~CommandFactory();
   /**
    //-------------------------- make_Command method for class CommandFactory  ------------------------------------//
    Make a dummy command object based on the code from the command file
    */
   Command* make_Command(std::string code) const;
   /**
    //-------------------------- buildCommandsByFactory method for class CommandFactory  ------------------------------------//
    Method to make a dummy command object
    */
   Command* buildCommandsByFactory(std::string code) const;
};
