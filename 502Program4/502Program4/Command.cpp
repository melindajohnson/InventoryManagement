
/*
 Command.cpp
 Created by Melinda Stannah Stanley Jothiraj on 11/27/19.
 Student number- 1978413
 Command class: is a Abstract class that has 
 some protected strings
 a create method to create dummy command objects
 a execute method to execute the right command
 a read input method that reads from the input command file
 ---------------------------------------------------------------------------
 */

#include "Command.h"

/**
 //-------------------------- Default constructor  for class Command  ------------------------------------//
 Create a new Command Object
 */
Command::Command(){
   
}
/**
 //-------------------------- Destructor for class Command  ------------------------------------//
 Destroys object and frees memory allocated by object.
 */
Command:: ~Command(){
   
}
/**
 //-------------------------- readInput method  for class Command  ------------------------------------//
 Reads from the input command file and sets the protected data memebers
 */
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
