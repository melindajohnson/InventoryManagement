
#include "CommandFactory.h"

CommandFactory::CommandFactory() {
   commandHash->insert("S", new SellCommand);
   commandHash->insert("B", new BuyCommand);
   commandHash->insert("H", new HistoryCommand);
   commandHash->insert("D", new DisplayCommand);
   commandHash->insert("C", new CustomerCommand);
}

CommandFactory:: ~CommandFactory() {
   commandHash->clear();
}

Command* CommandFactory::make_Command(std::string code) const {
   if(commandHash->containsKey(code)){
      Command* ptr = dynamic_cast<Command*>(commandHash->getValue(code));
      return ptr->create();
   }
   else return nullptr;
}

Command* CommandFactory::buildCommandsByFactory(std::string code) const{
    return make_Command(code);
}
