
#include <stdio.h>
#include <string>
#include "Command.h"
#include "SellCommand.h"
#include "BuyCommand.h"
#include "HistoryCommand.h"
#include "DisplayCommand.h"
#include "CustomerCommand.h"
#include "Hashtable.h"
const static int numberOfItems = 10;

class CommandFactory
{
private:
   Hashtable *commandHash = new Hashtable(numberOfItems);
   
public:
   CommandFactory();
   virtual ~CommandFactory();
   Command* make_Command(std::string code) const;
};
