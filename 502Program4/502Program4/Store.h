/*
 Store.h
 Created by Melinda Stannah Stanley Jothiraj on 02/25/2020.
 Student number- 1978413
 The Store class contains a Store Respository
 It reads the input files and sets data into the store using the following methods
 The process data file that does the following
 1.Fill inventory - reads the inventory file and creates a hashtable of Item trees containing Items
 2.Fill cutsomer date - reads the customer file and creates a hashtable of Customers and a tree of the same Cutsomers
 3.Process Transaction - reads the command file and creates the executes necessary command
 ---------------------------------------------------------------------------
 */

#pragma once
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "StoreRepository.h"
#include "CommandFactory.h"
#include "CustomerRepository.h"

class Store{
private:
   
   StoreRepository *myStore = nullptr; 
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
   
   
public:
   
   /**
    //-------------------------- Default constructor for class Store  ------------------------------------//
    Create a new Store Object
    */
   Store();
   
   /**
    //-------------------------- Destructor for class Store  ------------------------------------//
    Destroys object and frees memory allocated by object.
    */
   virtual ~Store();
   
   /**
    //-------------------------- processDataFiles ------------------------------------//
    Preconditions: A store object is created
    Postconditions: The myStore is filled with data
    */
   void processDataFiles(std::ifstream &inventoryFile, std::ifstream &customerFile, std::ifstream &commandfile);
   
   
};
