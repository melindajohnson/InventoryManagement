
#include "TransactionItem.h"
/**
 //-------------------------- Default constructor  for class TransactionItem  ------------------------------------//
 Create and new TransactionItem Object
 */
TransactionItem::TransactionItem(){
   
}

/**
 //-------------------------- Parametric constructor  for class TransactionItem  ------------------------------------//
 Create and new Item Object with
 */
TransactionItem::TransactionItem(std::string type, Item* ptr1){
   code = type;
   itemPtr = ptr1;
}
/**
 //-------------------------- Destructor  for class TransactionItem  ------------------------------------//
 Destroys object and frees memory allocated by object.
 */
TransactionItem:: ~TransactionItem(){
   
}

/*
 //--------------------------Overloaded output operator <<  ------------------------------------//
 
 */
std::ostream& operator<<(std::ostream& out, const TransactionItem& c){
   out << c.code << "->";
   out << c.itemPtr->toStringWithoutCount();
   return out;
}

   /**
    *  Output a textual representation of this instance to the output stream.
    *  @pre This instance must be initialized.
    *  @post A textual representation of this instance is appended to a string and returned
    *  @return A textual representation of this instance is appended to a string
    */
   std::string TransactionItem::toString()const{
      return code + itemPtr->toStringWithoutCount();
   }
