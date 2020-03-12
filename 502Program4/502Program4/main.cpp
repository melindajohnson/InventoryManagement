
#include <iostream>
#include <string>
#include <fstream>
#include "StoreManager.h"
#include "Command.h"

using namespace std;

int main() {
   
   // open file
   ifstream inventoryFile("hw4inventory.txt");
   ifstream customerFile("hw4customers.txt");
   ifstream commandfile("hw4commands.txt");
   
   if (!inventoryFile) {
      cerr << "inventoryFile  could not be opened." << endl;
      return 1;
   }
   if (!customerFile) {
      cerr << "customerFile could not be opened." << endl;
      return 1;
   }
   if (!commandfile) {
      cerr << "commandfile could not be opened." << endl;
      return 1;
   }
   
   //create a store object
   StoreManager s1;
   //process data files in store 1
   s1.processDataFiles(inventoryFile, customerFile, commandfile);
   
}
