
#include "Hashtable.h"

/**
 //-------------------------- Default construtcor ------------------------------------//
 Preconditions: None
 Postconditions: The Hashtable is created with table size of buckets
 */
Hashtable::Hashtable(){
   
}
///**
// //-------------------------- Parametric  construtcor ------------------------------------//
// Preconditions: None
// Postconditions: The Hashtable is created with table size of buckets
// */
//Hashtable::Hashtable(unsigned long buckets){
//  
//}
/**
 //-------------------------- Destructor  for class Hashtable  ------------------------------------//
 Destroys object and frees memory allocated by object.
 */
Hashtable::~Hashtable(){
   clear();
}

/**
 //-------------------------- insert method ------------------------------------//
 Preconditions: The Hashtable is created
 Postconditions: The Hashtable has a new Hashentry
 */
void Hashtable::insert(std::string k, HashValueType* v){
   int hashIndex = getHashIndex(k);
   HashNode *prev = NULL;
   HashNode *entry = table[hashIndex];
   while (entry != NULL && entry->key != k) {
      prev = entry;
      entry = entry->next;
   }
   if (entry == NULL) {
      entry = new HashNode;
      entry->key = k;
      entry->value = v;
      if (prev == NULL) {
         // insert as first bucket
         table[hashIndex] = entry;
      } else {
         prev->next = entry;
      }
   } else {
         // just update the value
      entry->value = v;
   }
}
/**
 //-------------------------- remove method ------------------------------------//
 Preconditions: The Hashtable is created and filled HashEntries
 Postconditions: a  Hashentry is removed based on the key k
 */
void Hashtable::remove(std::string k){
   int hashIndex = getHashIndex(k);
   HashNode *prev = NULL;
   HashNode *entry = table[hashIndex];
   
   while (entry != NULL && entry->key != k) {
      prev = entry;
      entry = entry->next;
   }
   
   if (entry == NULL) {
         // key not found
      return;
   }
   else {
      if (prev == NULL) {
            // remove first bucket of the list
         table[hashIndex] = entry->next;
      } else {
         prev->next = entry->next;
      }
      delete entry; //-----check for memory leaks
   }
}

/**
 //-------------------------- containsKey ------------------------------------//
 Preconditions: The Hashtable is created and filled HashEntries
 Postconditions: a boolean true if the key exists and false is not
 @return a boolean true if the key exists and false is not
 */
bool Hashtable::containsKey(std::string key){
   int hashIndex = getHashIndex(key);
   HashNode *entry = table[hashIndex];
   while (entry != NULL) {
      if (entry->key == key) {
         return true;
      }
   }
   return false;
}
/**
 //-------------------------- getValue ------------------------------------//
 Preconditions: The Hashtable is created and filled HashEntries
 Postconditions: HashValueType* from the Hashtable depending upon the key k
 @return HashValueType* from the Hashtable
 */
HashValueType* Hashtable::getValue(std::string k){
   int hashIndex = getHashIndex(k);
   HashNode *entry = table[hashIndex];
   while (entry != NULL) {
      if (entry->key == k) {
         return entry->value;
      }
      entry = entry->next;
   }
   return nullptr;
}
/**
 //-------------------------- isEmpty ------------------------------------//
 Preconditions:The Hashtable is created and filled HashEntries
 Postconditions: boolean true if Hashtable has no entries and false if not
 @return boolean true if Hashtable has no entries and false if not
 */
bool Hashtable::isEmpty(){
   return totalBuckets==0;
}


int Hashtable::getHashIndex(std::string k){
   int intCount = atoi(k.c_str());
   return intCount%totalBuckets;
}

/**
 //-------------------------- clear ------------------------------------//
 Preconditions: The Hashtable is created and filled HashEntries
 Postconditions: The Hashentries inside the hashable are all deallocated and deleted
 */
void Hashtable::clear(){
   for (int i = 0; i < totalBuckets; ++i) {
      HashNode *entry = table[i];
      while (entry != NULL) {
         HashNode *prev = entry;
         entry = entry->next;
         delete prev;
      }
      table[i] = NULL;
   }
   // destroy the hash table
   //delete [] table;
}
