
/*
 Store.h
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
#pragma once

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "ItemManager.h"
#include "BinarySearchTree.h"

#include "Item.h"
#include "ItemFactory.h"
#include "TransactionItem.h"
#include "Customer.h"
using namespace std;
const static int totalBuckets = 26;
const static int totalCustomers = 101;

class Store{
private:
 
   BinarySearchTree customerTree; // BinarySearchTree whose nodes point to customerTransactions
   Hashtable *treeHash = new Hashtable(totalBuckets); //Hashtable for inserting into respective item tree
   Hashtable *customerHash= new Hashtable(totalCustomers); //create a hashtable object for filling with customer data
   ItemManager itemManager;
   
   
   /**
    //-------------------------- FillInventory ------------------------------------//
    Preconditions: A store object is created
    Postconditions: The inventory tree is filled with items in the store
    */
   void FillInventory(ifstream &inventoryFile);
   /**
    //-------------------------- FillCustomerData ------------------------------------//
    Preconditions: A store object is created
    Postconditions: The customerData hashtable is filled with customer information
    */
   void FillCustomerData(ifstream &customerFile);
   /**
    //-------------------------- ProcessTransactions------------------------------------//
    Preconditions: A store object is created and inventorytree and customerData is filled with data
    Postconditions: The rootPtr of the Searchtree is initialized to a nullptr
    */
   void ProcessTransactions(ifstream &commandfile);
   
   
   
public:
   
   Store();
   /**
    //-------------------------- processDataFiles ------------------------------------//
    Preconditions: A store object is created and a hashtable object is created
    Postconditions: The inventory tree,inventoryHashtable, customerData Hashtable and transactionTree are all filled with data
    */
   void processDataFiles(ifstream &inventoryFile, ifstream &customerFile, ifstream &commandfile);
   
   void displayInventory(Hashtable& h1);
   void displayAllCustomer(Hashtable& h1);
};

