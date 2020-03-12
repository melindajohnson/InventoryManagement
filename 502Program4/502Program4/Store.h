
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
#include "BinarySearchTree.h"
#include "Comparable.h"
#include "ItemFactory.h"


const static int totalBuckets = 26;
const static int totalCustomers = 101;

class Store{
public:
 
   BinarySearchTree customerTree; // BinarySearchTree whose nodes point to customerTransactions
   Hashtable *treeHash = new Hashtable(totalBuckets); //Hashtable for inserting into respective item tree
   Hashtable *customerHash= new Hashtable(totalCustomers); //create a hashtable object for filling with customer data
   ItemFactory  itemFactory;
   Store();
   
  
};

