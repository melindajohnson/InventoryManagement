
#include "Command.h"

/**
 //-------------------------- Default constructor  for class Command  ------------------------------------//
 Create a new Command Object
 */
Command::Command(){
   
}

void Command::readInput(std::string commandString){
   std::stringstream  data(commandString);
   std::string line;
   
   int i = 0;
   while(std::getline(data,line,','))
   {
      tokens[i] = line;
      i++;
      data.get();
   }
   
   customerId = tokens[0];;
   itemCode = tokens[1];
   description = tokens[2] + ", " + tokens[3]+ ", " + tokens[4] + ", "+ tokens[5];
}
