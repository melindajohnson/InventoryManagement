
#pragma once
#include <stdio.h>
#include <vector>
#include "Item.h"
class TransactionEntry  {
private:
 
      std::string code;  //code would S for sell and B for Buy
      Item* itemPtr;
  
   
public:
   /**
    //-------------------------- Default constructor  for class TransactionItem  ------------------------------------//
    Create and new TransactionItem Object
    */
   TransactionEntry();
   
   /**
    //-------------------------- Parametric constructor  for class TransactionItem  ------------------------------------//
    Create and new TransactionItem Object
    */
   TransactionEntry(std::string code, Item* ptr);
   
   /**
    //-------------------------- Destructor  for class TransactionItem  ------------------------------------//
    Destroys object and frees memory allocated by object.
    */
   virtual ~TransactionEntry();
   
   /*
    //--------------------------Overloaded output operator <<  ------------------------------------//
    
    */
   friend std::ostream& operator<<(std::ostream& out, const TransactionEntry& c);
   
   std::string toString()const;
   
};
 
