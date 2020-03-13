/*
 TransactionEntry.h
 Created by Melinda Stannah Stanley Jothiraj on 02/25/2020.
 Student number- 1978413
 --The TransactionEntry class contains the private data member transaction code and a pointer to an Item object
 ---------------------------------------------------------------------------
 */

#include "TransactionEntry.h"
/**
 //-------------------------- Default constructor  for class TransactionEntry  ------------------------------------//
 Create and new TransactionEntry Object
 */
TransactionEntry::TransactionEntry(){
   
}

/**
 //-------------------------- Parametric constructor  for class TransactionEntry  ------------------------------------//
 Create and new TransactionEntry Object with
 */
TransactionEntry::TransactionEntry(std::string type, Item* ptr1){
   code = type;
   itemPtr = ptr1;
}
/**
 //-------------------------- Destructor  for class TransactionEntry  ------------------------------------//
 Destroys object and frees memory allocated by object.
 */
TransactionEntry:: ~TransactionEntry(){
   
}

/**
 *  Output a textual representation of this instance to the output stream.
 *  @pre This instance must be initialized.
 *  @post A textual representation of this instance is appended to a string and returned
 *  @return A textual representation of this instance is appended to a string
 */
std::ostream& operator<<(std::ostream& out, const TransactionEntry& c){
   out << c.toString();
   return out;
}

/**
 *  Output a textual representation of this instance to a string
 *  @pre This instance must be initialized.
 *  @post A textual representation of this instance is appended to a string. and returned
 *  @return A textual representation of this instance is appended to a string.
 */
std::string TransactionEntry::toString()const{
   return code + " -> "+ itemPtr->toStringWithoutCount() + "\n";
}
