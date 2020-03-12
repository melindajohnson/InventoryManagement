

#pragma once

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "StoreRepository.h"
#include "CommandFactory.h"
#include "Customer.h"

class Store{
private:
   StoreRepository *myStore;
   /**
    //-------------------------- FillInventory ------------------------------------//
    Preconditions: A store object is created
    Postconditions: The inventory tree is filled with items in the store
    */
   void FillInventory(std::ifstream &inventoryFile);
   /**
    //-------------------------- FillCustomerData ------------------------------------//
    Preconditions: A store object is created
    Postconditions: The customerData hashtable is filled with customer information
    */
   void FillCustomerData(std::ifstream &customerFile);
   /**
    //-------------------------- ProcessTransactions------------------------------------//
    Preconditions: A store object is created and inventorytree and customerData is filled with data
    Postconditions: The rootPtr of the Searchtree is initialized to a nullptr
    */
   void ProcessTransactions(std::ifstream &commandfile);
   void displayInventory(Hashtable& h1);
   
   
public:
   Store();
   
   /**
    //-------------------------- processDataFiles ------------------------------------//
    Preconditions: A store object is created and a hashtable object is created
    Postconditions: The inventory tree,inventoryHashtable, customerData Hashtable and transactionTree are all filled with data
    */
   void processDataFiles(std::ifstream &inventoryFile, std::ifstream &customerFile, std::ifstream &commandfile);
   
   
 //  void displayAllCustomer(Hashtable& h1);
   
};
