
#pragma once
#include <stdio.h>
#include <string>
#include <list>
#include <iterator>
#include "HashValueType.h"

class Hashtable{
private:
   struct HashEntry
   {
      std::list<HashValueType*> value;
      std::string key;
   };
   
   int totalBuckets;
   HashEntry table[];
   
public:
   /**
    //-------------------------- FillInventory ------------------------------------//
    Preconditions: A store object is created
    Postconditions: The inventory tree is filled with items in the store
    */
   Hashtable(int buckets);
   /**
    //-------------------------- FillInventory ------------------------------------//
    Preconditions: A store object is created
    Postconditions: The inventory tree is filled with items in the store
    */
   int keyToHash(const std::string key);
   /**
    //-------------------------- FillInventory ------------------------------------//
    Preconditions: A store object is created
    Postconditions: The inventory tree is filled with items in the store
    */
   void insert(std::string k, HashValueType* v);
   /**
    //-------------------------- FillInventory ------------------------------------//
    Preconditions: A store object is created
    Postconditions: The inventory tree is filled with items in the store
    */
   void remove(std::string k);
   /**
    //-------------------------- FillInventory ------------------------------------//
    Preconditions: A store object is created
    Postconditions: The inventory tree is filled with items in the store
    */
   bool containsValue(HashValueType* v);
   /**
    //-------------------------- FillInventory ------------------------------------//
    Preconditions: A store object is created
    Postconditions: The inventory tree is filled with items in the store
    */
   bool containsKey(std::string key);
   /**
    //-------------------------- FillInventory ------------------------------------//
    Preconditions: A store object is created
    Postconditions: The inventory tree is filled with items in the store
    */
   HashValueType* getValue(std::string k);
   /**
    //-------------------------- FillInventory ------------------------------------//
    Preconditions: A store object is created
    Postconditions: The inventory tree is filled with items in the store
    */
   bool isEmpty();
   /**
    //-------------------------- FillInventory ------------------------------------//
    Preconditions: A store object is created
    Postconditions: The inventory tree is filled with items in the store
    */
   void clear();
   /**
    //-------------------------- FillInventory ------------------------------------//
    Preconditions: A store object is created
    Postconditions: The inventory tree is filled with items in the store
    */
   
};


