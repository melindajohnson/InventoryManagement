
#include <iostream>
#include <string>
#include <fstream>
#include "Store.h"
#include "Hashtable.h"
using namespace std;

int main() {
   // open file
   ifstream inventoryFile("hw4inventory.txt");
   ifstream customerFile("hw4customers.txtt");
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
   
   Store s1; //create a store object
   Hashtable customerData; //create a hashtable object for filling with customer data
   
   //process data files in store 1
   s1.processDataFiles(customerData, inventoryFile, customerFile, commandfile);
   
}
