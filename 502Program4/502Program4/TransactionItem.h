
#pragma once
#include <stdio.h>
#include <vector>
#include "Item.h"
class TransactionItem  {
private:
 
      std::string code;  //code would S for sell and B for Buy
      Item* ptr;
  
   
public:
   /**
    //-------------------------- Default constructor  for class TransactionItem  ------------------------------------//
    Create and new TransactionItem Object
    */
   TransactionItem();
   
   /**
    //-------------------------- Parametric constructor  for class TransactionItem  ------------------------------------//
    Create and new TransactionItem Object
    */
   TransactionItem(std::string code, Item* ptr);
   
   /**
    //-------------------------- Destructor  for class TransactionItem  ------------------------------------//
    Destroys object and frees memory allocated by object.
    */
   virtual ~TransactionItem();

   
};
 
