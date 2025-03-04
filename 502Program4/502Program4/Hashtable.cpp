
#include "Hashtable.h"

/**
 //-------------------------- Parametric  construtcor ------------------------------------//
 Preconditions: None
 Postconditions: The Hashtable is created with table size of buckets
 */
Hashtable::Hashtable(const int buckets){
   totalBuckets = buckets;
   table = new HashNode* [totalBuckets];
   for (unsigned int i = 0; i< totalBuckets; i++) {
      table[i] = nullptr;
   }
}
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
void Hashtable::insert(const std::string k, HashValueType* v){
   int hashIndex = getHashIndex(k);
   HashNode *prev = NULL;
   HashNode *entry = table[hashIndex];
   while (entry != NULL) {
      prev = entry;
      entry = entry->next;
   }
   if (entry == NULL) {
      entry = new HashNode;
      entry->key = k;
      entry->value = v;
      entry->next =nullptr;
      if (prev == NULL) {
         // insert as first bucket
         table[hashIndex] = entry;
         numberOfentries++;
      } else {
         prev->next = entry;
          numberOfentries++;
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
void Hashtable::remove(const std::string k){
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
         numberOfentries--;
      } else {
         prev->next = entry->next;
      }
      delete entry;
   }
}

/**
 //-------------------------- containsKey ------------------------------------//
 Preconditions: The Hashtable is created and filled HashEntries
 Postconditions: a boolean true if the key exists and false is not
 @return a boolean true if the key exists and false is not
 */
bool Hashtable::containsKey(const std::string key) const{
   int hashIndex = getHashIndex(key);
   HashNode *entry = table[hashIndex];
   while (entry != NULL) {
      if (entry->key == key) {
         return true;
      }
      entry = entry->next;
   }
  return false;
}
/**
 //-------------------------- getValue ------------------------------------//
 Preconditions: The Hashtable is created and filled HashEntries
 Postconditions: HashValueType* from the Hashtable depending upon the key k
 @return HashValueType* from the Hashtable
 */
HashValueType* Hashtable::getValue(const std::string k) const{
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
bool Hashtable::isEmpty() const{
   return totalBuckets==0;
}

/**
 //-------------------------- getHashIndex ------------------------------------//
 Preconditions: The Hashtable is created
 Postconditions: The parametric k is hashed
 @return hashcode of type integer
 */
int Hashtable::getHashIndex(const std::string k) const{

   int hashVal = 0;
   
   for(unsigned int i = 0; i<k.length();  i++)
      hashVal = 37*hashVal+k[i];
   
   hashVal %= totalBuckets;
   
   if(hashVal<0)
      hashVal += totalBuckets;
   
   return hashVal;
}

/**
 //-------------------------- clear ------------------------------------//
 Preconditions: The Hashtable is created and filled HashEntries
 Postconditions: The Hashentries inside the hashable are all deallocated and deleted
 */
void Hashtable::clear(){
   for (unsigned int i = 0; i < totalBuckets; ++i) {
      HashNode *entry = table[i];
      while (entry != NULL) {
         HashNode *prev = entry;
         entry = entry->next;
         delete prev;
      }
      table[i] = NULL;
   }
  //  destroy the hash table
  delete [] table;
}

/**
 //-------------------------- isEmpty ------------------------------------//
 Preconditions:The Hashtable is created and filled with HashEntries
 Postconditions: size of Hashtable is found out
 @return size of the  Hashtable i.e. number of entries
 */
int Hashtable::size() const{
   return totalBuckets;
}

/**
 //-------------------------- getHashIndex ------------------------------------//
 Preconditions: The Hashtable is created
 Postconditions: The values are added to a vector by traversing the list
 @return vector of values
 */
std::vector<HashValueType*> Hashtable::getContents() const{
   std::vector<HashValueType*> contents;
   for(unsigned int i=0; i< totalBuckets; i++){
      HashNode *curr = table[i];
      while(curr != nullptr){
      contents.push_back(table[i]->value);
      curr = curr->next;
      }
   }
   return contents;
}
