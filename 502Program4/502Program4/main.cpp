/**
 Problem Statement:
 A local collectibles store wishes to automate their inventory tracking system. Currently there are 3 types of items to be tracked which are,
 •   Coins
 •   Comic books
 •   Sports cards
 Five types of actions have to be also considered in the system:
 •   Sell: removes an item from the inventory
 •   Buy: adds an item to the inventory
 •   Display: outputs the entire inventory of the store, including the number of each item in inventory in the order first coins, then comic books and then sports cards.
 •   Customer: outputs all of the transactions for a customer, including the item (in chronological order)
 •   History: outputs the history for every customer, with the customers in alphabetical order.
 The program must initialize the contents of the inventory from a file, the customer list from another file, and process an arbitrary sequence of commands from a third file.

 Assumptions:
-- The inventoryfile has correct formatting, but the data could be invalid.
-- The customerfile has correct formatting, but the data could be invalid(duplicates)
-- The commandFile has correct formatting, but the data could be invalid i.e not available or error codes

ErroHandling:
-- In the inventoryfile in case of invalid code, the line is skipped and file reading continues
-- In the customerfile in case of invalid code, the line is skipped and file reading continues
-- In the commandFile in case of invalid code, error messages are printed for incorrect data and then file reading continues
---------------------------------------------------------------------------
*/
#include <iostream>
#include <string>
#include <fstream>
#include "Store.h"
#include "Command.h"
//#define _CRTDBG_MAP_ALLOC
//#include <cstdlib>
//#include <crtdbg.h>

using namespace std;

int main() {
   // _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
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
   Store s1;
   //process data files in store 1
   s1.processDataFiles(inventoryFile, customerFile, commandfile);
   
}
