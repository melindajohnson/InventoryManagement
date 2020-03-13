
/*
 StoreRepository.h
 Created by Melinda Stannah Stanley Jothiraj on 02/25/2020.
 Student number- 1978413
   The StoreRepository class contains
      a binary search trees to holds CustomerRepository
      a hashtable for items called the tree hash which contains a hashtable of pointers to Item trees which inturn have item pointers in them
      a hashtable for CustomerRepository called the cutsomerTree
      a Item factory to create Items whenever desired
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

class StoreRepository{
public:
   
   BinarySearchTree itemtree;
   BinarySearchTree customerTree; // BinarySearchTree whose nodes point to customerTransactions
//   Hashtable *treeHash = new Hashtable(totalBuckets); //Hashtable for inserting item into respective item tree
   Hashtable *customerHash= new Hashtable(totalCustomers);//Hashtable for filling with customer data
   ItemFactory  itemFactory;
   
   
   
   /**
    //-------------------------- Default constructor for class StoreRepository  ------------------------------------//
    Create a new StoreRepository Object
    */
  StoreRepository();
   
   /**
    //-------------------------- Destructor for class StoreRepository  ------------------------------------//
    Destroys object and frees memory allocated by object.
    */
   virtual ~StoreRepository();
   
  
};

