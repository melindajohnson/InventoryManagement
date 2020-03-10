
/*
 Store.cpp
 Created by Melinda Stannah Stanley Jothiraj on 02/25/2020.
 Student number- 1978413
 The Store class contains two binary search trees -> one for the inventry and the other to holds Customer transactions.
 The Store class also contains a hashtable for inventory control which helps in easy addition or removal of inventory for items in the store.
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
#include "Store.h"

Store::Store(){
   std::cout << "out";
}
void Store::processDataFiles(Hashtable& customerData, ifstream &inventoryFile, ifstream &customerFile, ifstream &commandfile){
   FillInventory(inventoryFile);
      // FillCustomerData(customerData, customerFile);
      // ProcessTransactions(customerData, commandfile);
}
void Store::FillInventory(ifstream &inventoryFile){
   
   itemManager.buildItemsByFactory(inventoryFile, *treeHash);
   display(*treeHash);
   
}
void Store::FillCustomerData(Hashtable& customerData, ifstream &customerFile){
      //read customerdata file until eof
   for(;;){
         //read customer id and customer name
      if (customerFile.eof()) break;
      std::string id;
      std::string name;
      getline(customerFile, id, ',');          //get customer id
      customerFile.get();          //discard space
      getline(customerFile, name);    //get customer name
                                      //  int customerID = atoi(id.c_str());
                                      //   Customer *c1 = new Customer();
                                      // customerData.insert(customerID, c1);
   }
}
void Store::ProcessTransactions(Hashtable& customerData, ifstream &commandfile){
      //read command file until eof
   for(;;){
      
      char input=' '; //read command code
      switch(input)
      {
         case 'S':
               //read customer id and find out customer name in the customerData hashtable
               //increase inventory of the particular object by 1
               //transactionTree.insert(customerTransaction);
            break;
         case 'B':
               //read customer id and find out customer name in the customerData hashtable
               //reduce inventory of the particular object by 1
               //add customerTransaction in TransactionTree
            break;
         case 'C':
               //read customer id and find out customer name in the customerData hashtable
               //Search for Customer in TransactionTree and output transactions
            break;
         case 'D':
               //Inorder traversal of the InventoryTree outputs the entire inventory of the store
            break;
         case 'H':
               //Inorder traversal of the TransactionTree outputs the entire history of transactions that took place in the store along with the customer details
            break;
         default:
            std::cout << "Invalid Code." << std::endl;
      }
   }
}

void Store::display(Hashtable& h1){
   std::cout << endl;
   std::vector<HashValueType*> itemsContent = h1.getContents();
   for (auto it = begin (itemsContent); it != end (itemsContent); ++it) {
      BinarySearchTree *item = dynamic_cast<BinarySearchTree*>(*it);
      if(item != nullptr){
       std::cout << *item;
      }
   }
}
