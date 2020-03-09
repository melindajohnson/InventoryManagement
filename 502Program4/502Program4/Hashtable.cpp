
#include "Hashtable.h"

/**
 //-------------------------- Default construtcor ------------------------------------//
 Preconditions: None
 Postconditions: The Hashtable is created with table size of buckets
 */
Hashtable::Hashtable(){
   
}
/**
 //-------------------------- Parametric  construtcor ------------------------------------//
 Preconditions: None
 Postconditions: The Hashtable is created with table size of buckets
 */
Hashtable::Hashtable(int buckets){
   
}
/**
 //-------------------------- Destructor  for class Hashtable  ------------------------------------//
 Destroys object and frees memory allocated by object.
 */
Hashtable::~Hashtable(){
   
}

/**
 //-------------------------- insert method ------------------------------------//
 Preconditions: The Hashtable is created
 Postconditions: The Hashtable has a new Hashentry
 */
void Hashtable::insert(std::string k, HashValueType* v){
   
}
/**
 //-------------------------- remove method ------------------------------------//
 Preconditions: The Hashtable is created and filled HashEntries
 Postconditions: a  Hashentry is removed based on the key k
 */
void Hashtable::remove(std::string k){

}
/**
 //-------------------------- containsValue ------------------------------------//
 Preconditions:The Hashtable is created and filled HashEntries
 Postconditions: a boolean true if the value exists and false is not
 @return a boolean true if the value exists and false is not
 */
bool Hashtable::containsValue(HashValueType* v){
    return true;
}
/**
 //-------------------------- containsKey ------------------------------------//
 Preconditions: The Hashtable is created and filled HashEntries
 Postconditions: a boolean true if the key exists and false is not
 @return a boolean true if the key exists and false is not
 */
bool Hashtable::containsKey(std::string key){
    return true;
}
/**
 //-------------------------- getValue ------------------------------------//
 Preconditions: The Hashtable is created and filled HashEntries
 Postconditions: HashValueType* from the Hashtable depending upon the key k
 @return HashValueType* from the Hashtable
 */
HashValueType* Hashtable::getValue(std::string k){
   return new HashValueType;
}
/**
 //-------------------------- isEmpty ------------------------------------//
 Preconditions:The Hashtable is created and filled HashEntries
 Postconditions: boolean true if Hashtable has no entries and false if not
 @return boolean true if Hashtable has no entries and false if not
 */
bool Hashtable::isEmpty(){
   return true;
}
