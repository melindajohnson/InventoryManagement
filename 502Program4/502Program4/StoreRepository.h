
/*
 StoreRepository.h
 Created by Melinda Stannah Stanley Jothiraj on 02/25/2020.
 Student number- 1978413
   The StoreRepository class contains
      a binary search trees to point to CustomerRepository objects
      a binary search trees to point to Item objects
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
   
   BinarySearchTree itemtree; // BinarySearchTree whose nodes point to items
   BinarySearchTree customerTree; // BinarySearchTree whose nodes point to customerTransactions
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

