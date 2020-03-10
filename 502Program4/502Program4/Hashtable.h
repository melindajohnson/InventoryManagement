/*
 Hashtable.h
 Created by Melinda Stannah Stanley Jothiraj on 02/25/2020.
 Student number- 1978413
 The Store class contains:
   -- A struct Hashentry which contains:
         -- a value which is list of pointers to HashValueType objects
         -- a key which is a string
   -- A int totalBuckets
   -- A pointer to table of Hashentries
 ---------------------------------------------------------------------------
 */
#pragma once
#include <stdio.h>
#include <string>
#include <vector>
#include <iterator>
#include "HashValueType.h"
static const int totalBuckets = 101;
class Hashtable{
private:
   struct HashNode
   {
      HashValueType* value;
      int key;
      HashNode* next;
   };
   
   
   HashNode **table;
   int numberOfentries = 0;
   
   /**
    //-------------------------- keyToHash ------------------------------------//
    Preconditions: The Hashtable is created
    Postconditions: The parametric Key is hashed
    @return hashcode of type integer
    */
   int keyToHash(const int key);
   
   /**
    //-------------------------- clear ------------------------------------//
    Preconditions: The Hashtable is created and filled HashEntries
    Postconditions: The Hashentries inside the hashable are all deallocated and deleted
    */
   void clear();
   
public:
   /**
    //-------------------------- Default construtcor ------------------------------------//
    Preconditions: None
    Postconditions: The Hashtable is created with table size of buckets
    */
   Hashtable();
   /**
    //-------------------------- Parametric  construtcor ------------------------------------//
    Preconditions: None
    Postconditions: The Hashtable is created with table size of buckets
    */
   Hashtable(int buckets);
   /**
    //-------------------------- Destructor  for class Hashtable  ------------------------------------//
    Destroys object and frees memory allocated by object.
    */
   virtual ~Hashtable();
   
   /**
    //-------------------------- insert method ------------------------------------//
    Preconditions: The Hashtable is created
    Postconditions: The Hashtable has a new Hashentry
    */
   void insert(int k, HashValueType* v);
   /**
    //-------------------------- remove method ------------------------------------//
    Preconditions: The Hashtable is created and filled HashEntries
    Postconditions: a  Hashentry is removed based on the key k
    */
   void remove(int k);
   
   /**
    //-------------------------- containsKey ------------------------------------//
    Preconditions: The Hashtable is created and filled HashEntries
    Postconditions: a boolean true if the key exists and false is not
    @return a boolean true if the key exists and false is not
    */
   bool containsKey(int key);
   /**
    //-------------------------- getValue ------------------------------------//
    Preconditions: The Hashtable is created and filled HashEntries
    Postconditions: HashValueType* from the Hashtable depending upon the key k
    @return HashValueType* from the Hashtable
    */
   HashValueType* getValue(int k);
   /**
    //-------------------------- isEmpty ------------------------------------//
    Preconditions:The Hashtable is created and filled HashEntries
    Postconditions: boolean true if Hashtable has no entries and false if not
    @return boolean true if Hashtable has no entries and false if not
    */
   bool isEmpty();
   
   int getHashIndex(int k);
};


