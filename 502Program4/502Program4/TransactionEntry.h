/*
 TransactionEntry.h
 Created by Melinda Stannah Stanley Jothiraj on 02/25/2020.
 Student number- 1978413
 --The TransactionEntry class contains the private data member transaction code and a pointer to an Item object
 ---------------------------------------------------------------------------
 */

#pragma once
#include <stdio.h>
#include <vector>
#include "Item.h"
class TransactionEntry  {
private:
 
      std::string code;  //code would S for sell and B for Buy
      Item* itemPtr = nullptr;
  
   
public:
   /**
    //-------------------------- Default constructor  for class TransactionEntry  ------------------------------------//
    Create and new TransactionEntry Object
    */
   TransactionEntry();
   
   /**
    //-------------------------- Parametric constructor  for class TransactionEntry  ------------------------------------//
    Create and new TransactionEntry Object
    */
   TransactionEntry(std::string code, Item* ptr);
   
   /**
    //-------------------------- Destructor  for class TransactionEntry  ------------------------------------//
    Destroys object and frees memory allocated by object.
    */
   virtual ~TransactionEntry();
   
   /**
    *  Output a textual representation of this instance to the output stream.
    *  @pre This instance must be initialized.
    *  @post A textual representation of this instance is appended to a output stream. and returned
    *  @return A textual representation of this instance is appended to a output stream.
    */
   friend std::ostream& operator<<(std::ostream& out, const TransactionEntry& c);
   
   /**
    *  Output a textual representation of this instance to a string
    *  @pre This instance must be initialized.
    *  @post A textual representation of this instance is appended to a string. and returned
    *  @return A textual representation of this instance is appended to a string.
    */
   std::string toString()const;
   
};
 
