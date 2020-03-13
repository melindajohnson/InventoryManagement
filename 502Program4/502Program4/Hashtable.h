/*
 Hashtable.h
 Created by Melinda Stannah Stanley Jothiraj on 02/25/2020.
 Student number- 1978413
 The Store class contains:
   -- A struct HashNode which contains:
         -- a value which is Linked list of pointers HashValueType objects
         -- a key which is a string
         -- a HashNode next
   -- A int totalBuckets
   -- A int number of entries in the Hashtable 
   -- A pointer to table of Hashentries
 ---------------------------------------------------------------------------
 */
#pragma once
#include <stdio.h>
#include <string>
#include <vector>
#include <iterator>
#include "HashValueType.h"

class Hashtable{
private:
   struct HashNode
   {
      HashValueType* value;
      std::string key;
      HashNode* next;
   };
   
   HashNode **table;
   unsigned int totalBuckets = 0;
   int numberOfentries = 0;
   
  
public:
  
   /**
    //-------------------------- Parametric  construtcor ------------------------------------//
    Preconditions: None
    Postconditions: The Hashtable is created with table size of buckets
    */
   Hashtable(const int buckets);
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
   void insert(const std::string k, HashValueType* v);
   /**
    //-------------------------- remove method ------------------------------------//
    Preconditions: The Hashtable is created and filled HashEntries
    Postconditions: a  Hashentry is removed based on the key k
    */
   void remove(const std::string k);
   
   /**
    //-------------------------- containsKey ------------------------------------//
    Preconditions: The Hashtable is created and filled HashEntries
    Postconditions: a boolean true if the key exists and false is not
    @return a boolean true if the key exists and false is not
    */
   bool containsKey(const std::string key) const;
   /**
    //-------------------------- getValue ------------------------------------//
    Preconditions: The Hashtable is created and filled HashEntries
    Postconditions: HashValueType* from the Hashtable depending upon the key k
    @return HashValueType* from the Hashtable
    */
   HashValueType* getValue(const std::string k) const;
   /**
    //-------------------------- isEmpty ------------------------------------//
    Preconditions:The Hashtable is created and filled HashEntries
    Postconditions: boolean true if Hashtable has no entries and false if not
    @return boolean true if Hashtable has no entries and false if not
    */
   bool isEmpty() const;
   
   /**
    //-------------------------- isEmpty ------------------------------------//
    Preconditions:The Hashtable is created and filled with HashEntries
    Postconditions: size of Hashtable is found out
    @return size of the  Hashtable i.e. number of entries
    */
   int size() const;
   
   /**
    //-------------------------- getHashIndex ------------------------------------//
    Preconditions: The Hashtable is created
    Postconditions: The parametric k is hashed
    @return hashcode of type integer
    */
   int getHashIndex(const std::string k) const;
   
   /**
    //-------------------------- clear ------------------------------------//
    Preconditions: The Hashtable is created and filled HashEntries
    Postconditions: The Hashentries inside the hashable are all deallocated and deleted
    */
   void clear();
   
   /**
    //-------------------------- getHashIndex ------------------------------------//
    Preconditions: The Hashtable is created
    Postconditions: The values are added to a vector by traversing the list
    @return vector of values
    */
   std::vector<HashValueType*> getContents() const;
};


