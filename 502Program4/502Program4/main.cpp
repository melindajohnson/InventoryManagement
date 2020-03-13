/**
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
   Store s1;
   //process data files in store 1
   s1.processDataFiles(inventoryFile, customerFile, commandfile);
   
}
