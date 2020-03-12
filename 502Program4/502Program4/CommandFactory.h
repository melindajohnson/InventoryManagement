
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
   Hashtable *commandHash = new Hashtable(numberOfCommand);
   
public:
   CommandFactory();
   virtual ~CommandFactory();
   Command* make_Command(std::string code) const;
   Command* buildCommandsByFactory(std::string code) const;
};
